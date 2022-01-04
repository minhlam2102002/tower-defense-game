#pragma once
#include "BaseObject.h"
class Tower;
class User;
// -------------------- Monster Class --------------------
class Monster : public BaseObject {
private:
	int HP;
	int speed;
	int curPoint = 0;
	bool endPoint = false;
	bool addMoney = false;
	int spawnTime;
	int cost = 50;
	int delay = 0;
	void Move(vector<Point>& path);
public:
	Monster(int _HP, int _speed, int _spawnTime, string file_path);
	bool HPChange(int dmg);
	void Update(vector<Point>& path);
	bool IsLife() { return this->HP > 0; }
	bool IsSpawn() { return this->spawnTime <= 0; }
	bool IsEnd() { return this->endPoint; }
	void SetPause(int time) { this->delay = time; }
	int GetCurPoint() { return curPoint; }
	void AttackTower(Tower* tower);
	void AddUserMoney(User* player);
};
// -------------------- MonsterList Class --------------------
class MonsterList
{
private:
public:
	bool allDied = false;
	vector<Monster*> list;
	MonsterList(int numMonster);
	void AddMonster(Monster* m);
	void Update(vector<Point>& path);
	void AttackTower(Tower*);
	void AddUserMoney(User*);
};