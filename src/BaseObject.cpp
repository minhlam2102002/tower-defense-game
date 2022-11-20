#include "BaseObject.h"

BaseObject::BaseObject() {
    this->obj = nullptr;
}
BaseObject::~BaseObject() {
    Free();
}
void BaseObject::setRect(const int& x, const int& y) {
    rect.x = x;
    rect.y = y;
}
void BaseObject::setRect(const Point& p) {
    rect.x = p.x;
    rect.y = p.y;
}
void BaseObject::setCenterRect(const Point& p) {
    rect.x = p.x - rect.w / 2;
    rect.y = p.y - rect.h / 2;
}
Point GetPosition() {
    return Point(rect.x, rect.y);
}
Point GetCenterPosition() { 
    return Point(rect.x + rect.w / 2, rect.y + rect.h / 2); 
}
SDL_Rect GetRect() const { return rect; }
SDL_Rect* GetRectPointer() { return &rect; }
SDL_Texture* GetObject() const { return obj; }
bool BaseObject::LoadImg(std::string path) {
    SDL_Texture* new_texture = NULL;
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if (load_surface != NULL) {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, MainScreen->COLOR_KEY_R, MainScreen->COLOR_KEY_B, MainScreen->COLOR_KEY_G));
        new_texture = SDL_CreateTextureFromSurface(MainScreen->g_screen, load_surface);
        if (new_texture != NULL) {
            rect.w = load_surface->w;
            rect.h = load_surface->h;
        } else {
            cout << "error";
        }
        SDL_FreeSurface(load_surface);
    } else {
        cerr << "Error image load: " << IMG_GetError() << endl;
        cout << path << endl;
    }
    obj = new_texture;
    if (obj == NULL) {
        cerr << "Error image load: " << IMG_GetError() << endl;
        cout << path << endl;
    }
    return obj != NULL;
}
void BaseObject::Render(const SDL_Rect* clip) {
    SDL_Rect renderquad = {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopy(MainScreen->g_screen, obj, clip, &renderquad);
}
void BaseObject::Free() {
    if (obj != NULL) {
        SDL_DestroyTexture(obj);
        obj = NULL;
        rect.w = 0;
        rect.h = 0;
    }
}

TextObject::TextObject() {
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
    texture_ = NULL;
}
void TextObject::SetColor(const int& num) {
    if (num == RED_TEXT) {
        SDL_Color color = {255, 0, 0};
        text_color_ = color;
    } else if (num == WHITE_TEXT) {
        SDL_Color color = {255, 255, 255};
        text_color_ = color;
    } else {
        SDL_Color color = {0, 0, 0};
        text_color_ = color;
    }
}
bool TextObject::LoadFromRenderText(TTF_Font* font) {
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, this->_text.c_str(), text_color_);
    if (text_surface) {
        texture_ = SDL_CreateTextureFromSurface(MainScreen->g_screen, text_surface);
        widthText = text_surface->w;
        heightText = text_surface->h;
        SDL_FreeSurface(text_surface);
    }
    return texture_ != NULL;
}
void TextObject::RenderText(int xp, int yp, SDL_Rect* clip, double Angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = {xp, yp, widthText, heightText};
    if (clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(MainScreen->g_screen, texture_, clip, &renderQuad, Angle, center, flip);
}
TextObject::~TextObject() {}