#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

using namespace std;

class Screen {
public:
    SDL_Window* window = nullptr;
    SDL_Renderer* screen = nullptr;
    TTF_Font* font = nullptr;
    SDL_Event event;
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGH;
    static int SCREEN_BPP;
    static int COLOR_KEY_R;
    static int COLOR_KEY_G;
    static int COLOR_KEY_B;
    bool init();
    void close();
};

int Screen::SCREEN_WIDTH = 600;
int Screen::SCREEN_HEIGH = 400;
int Screen::SCREEN_BPP = 32;
int Screen::COLOR_KEY_R = 255;
int Screen::COLOR_KEY_G = 255;
int Screen::COLOR_KEY_B = 255;