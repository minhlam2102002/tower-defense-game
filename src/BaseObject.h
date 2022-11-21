#pragma once
#include "App.h"
// #include "Audio.h"

struct Point {
    int x, y;
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(const int& _x, const int& _y) {
        this->x = _x;
        this->y = _y;
    }
    int distanceTo(Point p) {
        return distanceBetween(*this, p);
    }
    int distanceTo(int x, int y) {
        return distanceTo(Point(x, y));
    }
    static int distanceBetween(const Point& a, const Point& b) {
        return hypot(a.x - b.x, a.y - b.y);
    }
};
class BaseObject {
public:
    SDL_Texture* texture;
    SDL_Rect rect;

public:
    BaseObject();
    BaseObject(const string&, SDL_Rect);
    BaseObject(const string&);
    ~BaseObject();
    virtual void loadImage(const string&);
    virtual void render(const SDL_Rect* clip = nullptr);
};
class Text : public BaseObject {
private:
    string text;
    SDL_Color color;

public:
    Text(const string&, const SDL_Color&);
    void loadFromRenderText(TTF_Font*);
    void render(SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
