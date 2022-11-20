#pragma once
#include "BaseObject.h"
class MachineList;
class Machine;
class MonsterList;
// -------------------- User Class --------------------
class User : public BaseObject {
private:
    int money;
    BaseObject* menu;
    vector<Machine*> machineModel;
    int cur_model_id;
    const int bomp_cost = 1000;
    const int ice_cost = 500;

public:
    User(int money);
    void RenderMenu();
    string MoneyText() { return to_string(money) + " BTC "; }
    void AddMoney(int m) { money += m; }
    void AddMachineEvent();
    void AddMachine(MachineList* machineList);
    void HandleEvent(MachineList* machineList, MonsterList* monsterList);
    void UseBomp(MonsterList* monsterList);
    void UseIce(MonsterList* monsterList);
};
// -------------------- Tower Class --------------------
class Tower : public BaseObject {
private:
    int HP;

public:
    Tower() { HP = 1000; }
    Tower(int _HP) { HP = _HP; }
    bool isLife();
    string Text();
    void MonsterAttack(int damage);
    ~Tower(){};
};