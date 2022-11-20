#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

using namespace std;

class App {
private:
    static App* app;
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGH;
    static int SCREEN_BPP;
    static int COLOR_KEY_R;
    static int COLOR_KEY_G;
    static int COLOR_KEY_B;
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    App* getInstance();
    App();
    ~App();
    bool init();
    void close();
};

App* App::app = nullptr;
int App::SCREEN_WIDTH = 600;
int App::SCREEN_HEIGH = 400;
int App::SCREEN_BPP = 32;
int App::COLOR_KEY_R = 255;
int App::COLOR_KEY_G = 255;
int App::COLOR_KEY_B = 255;