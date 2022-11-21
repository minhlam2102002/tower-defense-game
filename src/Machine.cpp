#include "Machine.h"

Machine::Machine(string name) : BaseObject(name) {
    this->range = 100;
    this->money = 100;
    this->reload = 100;
}
Machine::Machine(string name, SDL_Rect _rect) : Machine(name) {
    this->rect = _rect;
}

void Machine::shotMonster() {

}