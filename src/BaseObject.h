#pragma once
#include "Music.h"
#include "Screen.h"

class Point {
public:
    int x;
    int y;

public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(const int _x, const int _y) {
        x = _x;
        y = _y;
    }
    int Distance(int x, int y) {
        return sqrt((x - this->x) * (x - this->x) + (y - this->y) * (y - this->y));
    }
    static int Distance2Point(Point a, Point b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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
public:
    static Screen* MainScreen;
    static Music* musicControl;

protected:
    SDL_Texture* p_object_;
    SDL_Rect rec_;

public:
    BaseObject();
    ~BaseObject();
    void setRect(const int& x, const int& y) {
        rec_.x = x;
        rec_.y = y;
    }
    void setRect(Point p) {
        rec_.x = p.x;
        rec_.y = p.y;
    }
    void setCenterRect(Point p) {
        rec_.x = p.x - rec_.w / 2;
        rec_.y = p.y - rec_.h / 2;
    }
    Point GetPosition() { return Point(rec_.x, rec_.y); }
    Point GetCenterPosition() { return Point(rec_.x + rec_.w / 2, rec_.y + rec_.h / 2); }
    SDL_Rect GetRect() const { return rec_; }
    SDL_Rect* GetRectPointer() { return &rec_; }
    SDL_Texture* GetObject() const { return p_object_; }
    bool LoadImg(std::string path);
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
