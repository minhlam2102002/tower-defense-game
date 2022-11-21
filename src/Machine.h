#pragma once
#include "BaseObject.h"

class Machine : public BaseObject {
private:
    int range;
    int money;
    int reload;

public:
    Machine(string);
    Machine(string, SDL_Rect);
    void shotMonster();
};