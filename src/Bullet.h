#include "Monster.h"

class Bullet : public BaseObject {
private:
    int damage = 20;
    int speed = 8;
    Monster* target;

public:
    Bullet(Point, Monster*);
    void move();
};
