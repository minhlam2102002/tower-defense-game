#include "BaseObject.h"

BaseObject::BaseObject() {
    this->texture = nullptr;
}
BaseObject::BaseObject(const string& filePath) : BaseObject() {
    this->loadImage(filePath);
}
BaseObject::BaseObject(const string& filePath, SDL_Rect _rect) : BaseObject(filePath) {
    this->rect = _rect;
    cout << this->rect.x << " " << this->rect.y << " " << this->rect.w << " " << this->rect.h << endl;
}
BaseObject::~BaseObject() {
    SDL_DestroyTexture(texture);
}
void BaseObject::loadImage(const string& filePath) {
    this->texture = IMG_LoadTexture(App::getRenderer(), filePath.c_str());
    // SDL_Surface* surface = IMG_Load(filePath.c_str());
    // if (surface != nullptr) {
    //     SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, App::COLOR_KEY_R, App::COLOR_KEY_B, App::COLOR_KEY_G));
    //     this->texture = SDL_CreateTextureFromSurface(App::getInstance()->renderer, surface);
    //     if (this->texture == nullptr) {
    //         cout << "Load texture from " << filePath << " error." << IMG_GetError() << endl;
    //     }
    //     SDL_FreeSurface(surface);
    // } else {
    //     cout << "Load surface from " << filePath << " error." << IMG_GetError() << endl;
    // }
}
void BaseObject::render(const SDL_Rect* clip) {
    SDL_RenderCopy(App::getRenderer(), texture, clip, &this->rect);
}
// ----------------------------------------------------------------
Text::Text(const string& _text, const SDL_Color& _color) : BaseObject() {
    this->text = _text;
    this->color = _color;
}
void Text::loadFromRenderText(TTF_Font* font) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, this->text.c_str(), this->color);
    if (surface != nullptr) {
        this->texture = SDL_CreateTextureFromSurface(App::getRenderer(), surface);
        this->rect.w = surface->w;
        this->rect.h = surface->h;
        SDL_FreeSurface(surface);
    } else {
        cout << "Load surface from text error " << TTF_GetError() << endl;
    }
}
void Text::render(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(App::getRenderer(), texture, clip, &this->rect, angle, center, flip);
}