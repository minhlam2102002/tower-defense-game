#include "Screen.h"

bool Screen::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    this->window = SDL_CreateWindow(
        "Tower Defense", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, 
        SCREEN_HEIGH, 
        SDL_WINDOW_SHOWN
    );
    if (this->window == nullptr) 
        return false;
    this->screen = SDL_CreateRenderer(this->window, 1, SDL_RENDERER_ACCELERATED);
    if (this->screen == nullptr) return false;
    SDL_SetRenderDrawColor(this->screen, 255, 255, 255, 255);
    int imgflags = IMG_INIT_PNG;
    if (!(IMInit(imgflags) && imgflags))
        sucess = false;
    if (TTF_Init() == -1) {
        sucess = false;
    }
    this->font = TTF_OpenFont("dpquake_.ttf", 20);
    if (this->font == NULL) {
        return false;
    }
    return sucess;
}

void Screen::close() {
    SDL_DestroyRenderer(screen);
    screen = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    IMQuit();
    SDL_Quit();
}