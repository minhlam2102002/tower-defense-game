#include "Screen.h"
bool Screen::InitData() {
	bool sucess = true;
	int flat = SDL_Init(SDL_INIT_VIDEO);
	if (flat < 0) return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGH, SDL_WINDOW_SHOWN);
	if (g_window == NULL) {
		sucess = false;
	}
	else {
		g_screen = SDL_CreateRenderer(g_window, 1, SDL_RENDERER_ACCELERATED);
		if(g_screen == NULL)
			sucess = false;
		else {
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
			int imgflags = IMG_INIT_PNG;
			if (!(IMG_Init(imgflags) && imgflags))
				sucess = false;
		}
	}
	if (TTF_Init() == -1) {
		sucess = false;
	}
	g_font_text = TTF_OpenFont("dpquake_.ttf", 20);
	if (g_font_text == NULL) { return false; }
	return sucess;
}

void Screen::close() {
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();
}