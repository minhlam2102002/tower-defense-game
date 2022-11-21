#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

using namespace std;

class App {
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
private:
    static App* app;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color backgroundColor;
public:
    static App* getInstance();
    static App* createInstance();
    static SDL_Renderer* getRenderer();
    App();
    ~App();
    void setRenderColor(SDL_Color);
    void clearScreen();
    void presentScreen();
    void close();
};