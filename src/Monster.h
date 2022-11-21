#pragma once
#include "BaseObject.h"

// -------------------- Monster Class --------------------
class Monster : public BaseObject {
private:
    int HP;
    int speed;
    int spawnTime;
    int cost = 50;
    int delay = 0;
    void Move(vector<Point>& path);

public:

};
