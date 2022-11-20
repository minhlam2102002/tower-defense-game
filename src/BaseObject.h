#pragma once
#include "App.h"
#include "Music.h"

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
class Time {
public:
    static int time;

public:
    static void Increase() {
        time++;
    }
    static int Get() {
        return time;
    }
};
class BaseObject {
protected:
    SDL_Texture* obj;
    SDL_Rect rect;

public:
    BaseObject();
    ~BaseObject();
    void setRect(const int& x, const int& y) {
        rect.x = x;
        rect.y = y;
    }
    void setRect(const Point& p) {
        rect.x = p.x;
        rect.y = p.y;
    }
    void setCenterRect(const Point& p) {
        rect.x = p.x - rect.w / 2;
        rect.y = p.y - rect.h / 2;
    }
    Point GetPosition() {
        return Point(rect.x, rect.y);
    }
    Point GetCenterPosition() { return Point(rect.x + rect.w / 2, rect.y + rect.h / 2); }
    SDL_Rect GetRect() const { return rect; }
    SDL_Rect* GetRectPointer() { return &rect; }
    SDL_Texture* GetObject() const { return obj; }
    bool LoadImg(string path);
    void Render(const SDL_Rect* clip = NULL);
    void Free();
};
class TextObject : public BaseObject {
private:
    string _text;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int widthText;
    int heightText;

public:
    enum TextColor {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };
    TextObject();
    ~TextObject();
    bool LoadFromFile(string path);
    bool LoadFromRenderText(TTF_Font* font);
    void SetText(const string& textValue) { _text = textValue; }
    void SetColor(const int&);
    void CreateGameText(TTF_Font* font);
    void Free();
    void RenderText(int xp, int yp, SDL_Rect* clip = NULL, double Angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    int GetWIdth() { return widthText; }
    int GetHeight() { return heightText; }
};
