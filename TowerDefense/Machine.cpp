#include "Machine.h"
#include "Monster.h"
// -------------------- Bullet Class --------------------
Bullet::Bullet(Point start, Monster* _m, int speed, int dmg) {
	m = _m;
	this->speed = speed;
	this->dmg = dmg;
	LoadImg("bullet.png");
	setRect(start);
}

void Bullet::Move() {
	Point mPos = m->GetCenterPosition();
	Point pos = GetCenterPosition();
	double direction = atan2(mPos.y - pos.y, mPos.x - pos.x);
	Point newPos = pos;
	newPos.x = pos.x + 1.0 * speed * cos(direction);
	newPos.y = pos.y + 1.0 * speed * sin(direction);
	if (Point::Distance2Point(pos, newPos) > Point::Distance2Point(pos, mPos)) {
		m->HPChange(this->dmg);
		pos = mPos;
		isEnd = true;
	} else {
		pos = newPos;
	}
	setCenterRect(pos);
}
void Bullet::Update() {
	Move();
	Render();
}
bool Bullet::GetIsEnd() { 
	return isEnd || !m->IsLife(); 
}
// -------------------- BulletList Class --------------------
void BulletList::addBullet(Point start, Monster* m, int speed, int dmg) {
	list.push_back(new Bullet(start, m, speed, dmg));
}

void BulletList::Update() {
	for (int i = 0; i < list.size(); i++) {
		if (list[i] && list[i]->GetIsEnd() == false) {
			list[i]->Update();
		}
		if (list[i] && list[i]->GetIsEnd()) {
			delete list[i];
			list[i] = NULL;
		}
	}
}
// -------------------- Machine Class --------------------
Machine::Machine(string file_path, int level) {
	this->Level = level;
	this->RangeBase = 60 * level;
	this->reloadTime = 20 - level * 5;
	this->file_path = file_path;
	this->bullet_dmg = 20 + level * 5;
	this->bullet_speed = 8 + level;
	LoadImg(file_path);
}
Machine::~Machine(){}
void Machine::ShotMonster(BulletList *bulletList, Monster* m) {
	int distance = Point::Distance2Point(m->GetCenterPosition(), GetCenterPosition());
	if (m->IsSpawn() && m->IsLife() && reload <= 0 && distance < this->RangeBase) {
		reload = reloadTime;
		bulletList->addBullet(GetCenterPosition(), m, bullet_speed, bullet_dmg);
	}
}
Machine* Machine::Clone() {
	Machine* m = new Machine(file_path, Level);
	return m;
}
// -------------------- MachineList Class --------------------
void MachineList::AddMachine(Machine* m) {
	list.push_back(m);
}
void MachineList::Render() {
	for (int i = 0; i < list.size(); i++) {
		list[i]->Render(NULL);
	}
}
bool MachineList::checkDuplicate(SDL_Rect rect) {
	for (int i = 0; i < pathRect.size(); i++) {
		if (SDL_HasIntersection(&pathRect[i], &rect)) {
			return true;
		}
	}
	for (int i = 0; i < list.size(); i++) {
		if (SDL_HasIntersection(list[i]->GetRectPointer(), &rect)) {
			return true;
		}
	}
	return false;
}
bool cmp(Monster*& a, Monster*& b) {
	return a->GetCurPoint() > b->GetCurPoint(); // 0 -> path.size() - 1
}
void MachineList::ShotMonster(MonsterList* monsterlist, BulletList* bulletList) {
	sort(monsterlist->list.begin(), monsterlist->list.end(), cmp);
	for (int i = 0; i < list.size(); i++) {
		list[i]->reload--;
		for (int j = 0; j < monsterlist->list.size(); j++) {
			this->list[i]->ShotMonster(bulletList, monsterlist->list[j]);
		}
	}
}