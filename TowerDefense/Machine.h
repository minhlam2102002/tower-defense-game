#pragma once
#include "BaseObject.h"

class Monster;
class MonsterList;
// -------------------- Bullet Class --------------------
class Bullet : public BaseObject {
private:
	int dmg = 20;
	int speed = 8;
	Monster* m;
	bool isEnd = false;
public:
	Bullet(Point start, Monster*, int, int);
	~Bullet() {}
	void setSpeed(int Speed) { speed = Speed; }
	int getSpeed() { return speed; }
	void Move();
	void Update();
	bool GetIsEnd();
};
// -------------------- BulletList Class --------------------
class BulletList {
private:
	vector<Bullet*> list;
public:
	void addBullet(Point, Monster*, int, int);
	void Update();
};
// -------------------- Machine Class --------------------
class Machine: public BaseObject {
private:
	int Level;
	string file_path;
	int RangeBase = 30;
	int reloadTime = 20;
	int bullet_speed;
	int bullet_dmg;
public:
	int reload = 0;
	int money;
	Machine(string fpath, int level);
	~Machine();
	void ShotMonster(BulletList*, Monster*);
	Machine* Clone();
	//void Update(Screen &MainScreen);
};
// -------------------- MachineList Class --------------------
class MachineList {
public:
	vector<SDL_Rect> pathRect;
	vector<Machine*> list;
public:
	void Render();
	void AddMachine(Machine*);
	bool checkDuplicate(SDL_Rect rect);
	void ShotMonster(MonsterList* monsterlist, BulletList* bulletList);
};