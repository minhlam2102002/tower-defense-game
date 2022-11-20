#include "Monster.h"

#include "User.h"

// -------------------- Monster Class --------------------
Monster::Monster(int _HP, int _speed, int _spawnTime, string file_path) {
    HP = _HP;
    speed = _speed;
    spawnTime = _spawnTime;
    cost = 50 + (HP / 10);
    LoadImg(file_path);
}
void Monster::Move(vector<Point>& path) {
    if (delay > 0) {
        delay--;
        return;
    }
    curPoint += speed;
    curPoint = min(curPoint, path.size() - 1);
    if (curPoint == path.size() - 1) endPoint = true;
    setRect(path[curPoint]);
}
void Monster::Update(vector<Point>& path) {
    if (!IsLife() || IsEnd()) return;
    if (spawnTime > 0) {
        spawnTime--;
        return;
    }
    Move(path);
    Render(NULL);
}
bool Monster::HPChange(int dmg) {
    if (this->HP > 0) {
        this->HP -= dmg;
        if (this->HP <= 0) {
            musicControl->PlaySoundEffect("monster_die");
            this->HP = 0;
        }
        return true;
    }
    return false;
}
void Monster::AttackTower(Tower* tower) {
    if (!IsSpawn()) return;
    if (IsEnd() && IsLife()) {
        tower->MonsterAttack(HP);
        HP = 0;
    }
}
void Monster::AddUserMoney(User* player) {
    if (!addMoney && !IsEnd() && !IsLife()) {
        player->AddMoney(cost);
        addMoney = true;
    }
}
// -------------------- MonsterList Class --------------------
MonsterList::MonsterList(int numMonster) {
    for (int i = 0; i < numMonster; i++) {
        int HP = i * 8 + 50;
        int speed = i % 3 + 2;  // from 2 to 4
        int spawnTime = i * 30 + 5;
        string img = "Monster" + to_string(i % 3) + ".png";  // 3 monster
        AddMonster(new Monster(HP, speed, spawnTime, img));
    }
}
void MonsterList::AddMonster(Monster* m) {
    list.push_back(m);
}
void MonsterList::Update(vector<Point>& path) {
    int cnt = 0;
    for (int i = 0; i < list.size(); i++) {
        list[i]->Update(path);
        if (list[i]->IsLife()) cnt++;
    }
    if (cnt == 0) allDied = true;
}
void MonsterList::AttackTower(Tower* tower) {
    for (int i = 0; i < list.size(); i++) {
        list[i]->AttackTower(tower);
    }
}
void MonsterList::AddUserMoney(User* player) {
    for (int i = 0; i < list.size(); i++) {
        list[i]->AddUserMoney(player);
    }
}
