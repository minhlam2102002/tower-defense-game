#include "Bullet.h"

Bullet::Bullet(Point begin, Monster* monster) {
    this->target = monster;
    this->speed = 20;
    this->damage = 20;
    this->loadImage("bullet.png");
    this->rect.x = begin.x;
    this->rect.y = begin.y;
}

void Bullet::move() {
    // Point targetPosition = this->target->getPosition();
    // Point currentPosition = Point(this->rect.x, this->rect.y);
    // double direction = atan2(mPos.y - pos.y, mPos.x - pos.x);
    // Point newPos = pos;
    // newPos.x = pos.x + 1.0 * speed * cos(direction);
    // newPos.y = pos.y + 1.0 * speed * sin(direction);
}