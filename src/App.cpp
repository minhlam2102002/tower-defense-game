#include "App.h"

App* App::getInstance() {
    if (app == nullptr) {
        app = new App();
    }
    return app;
}
App::App() {
    window = nullptr;
    renderer = nullptr;
    font = nullptr;
}

bool App::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return false;
    }
    // Create window
    this->window = SDL_CreateWindow(
        "Tower Defense", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        App::SCREEN_WIDTH, 
        App::SCREEN_HEIGH, 
        SDL_WINDOW_SHOWN
    );
    if (this->window == nullptr)  {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return false;
    }
    // Create renderer for window
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return false;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);

    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        cout << "IMG_Init Error: " << IMG_GetError() << endl;
        return false;
    }
    if (TTF_Init() == -1) {
        cout << "TTF_Init Error: " << TTF_GetError() << endl;
        return false;
    }
    this->font = TTF_OpenFont("../assets/fonts/dpquake_.ttf", 20);
    if (this->font == nullptr) {
        cout << "TTF_OpenFont Error: " << TTF_GetError() << endl;
        return false;
    }
    cout << "SDL init success" << endl;
    return true;
}

void App::close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
App::~App() {
    close();
    delete App::app->window;
    delete App::app->renderer;
    delete App::app->font;
    delete App::app;
}