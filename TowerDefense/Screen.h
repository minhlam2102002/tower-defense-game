#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#undef main
using namespace std;
class Screen{
public:
    SDL_Window* g_window = NULL;
    SDL_Renderer* g_screen = NULL;
    SDL_Event g_event;
    TTF_Font* g_font_text = NULL;
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGH = 400;
    const int SCREEN_BPP = 32;
    const int COLOR_KEY_R = 255;
    const int COLOR_KEY_G = 255;
    const int COLOR_KEY_B = 255;
    bool InitData();
    void close();
};
#endif // !
