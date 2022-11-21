#include "App.h"

App* App::app = nullptr;
int App::SCREEN_WIDTH = 1000;
int App::SCREEN_HEIGHT = 800;

App* App::getInstance() {
    if (App::app == nullptr) {
        App::app = new App();
    }
    return App::app;
}
App* App::createInstance() {
    if (App::app == nullptr) {
        App::app = new App();
    }
    return App::app;
}
SDL_Renderer* App::getRenderer() {
    return App::getInstance()->renderer;
}
App::App() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        exit(0);
    }
    // Create window
    this->window = SDL_CreateWindow(
        "Tower Defense", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        App::SCREEN_WIDTH, 
        App::SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN
    );
    if (this->window == nullptr)  {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        exit(0);
    }
    // Create renderer for window
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        exit(0);
    }
    // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    // set background color
    this->backgroundColor = {255, 255, 255, 255};
    this->setRenderColor(this->backgroundColor);
    // Initialize SDL_image
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        cout << "IMG_Init Error: " << IMG_GetError() << endl;
        exit(0);
    }
    // Initialize SDL_font
    if (TTF_Init() == -1) {
        cout << "TTF_Init Error: " << TTF_GetError() << endl;
        exit(0);
    }
    // Initialize SDL_font
    this->font = TTF_OpenFont("../assets/fonts/dpquake_.ttf", 20);
    if (this->font == nullptr) {
        cout << "TTF_OpenFont Error: " << TTF_GetError() << endl;
        exit(0);
    }
    cout << "SDL init success" << endl;
}
App::~App() {
    this->close();
}
void App::setRenderColor(SDL_Color color) {
    if (SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a) != 0) {
        cout << "SDL_SetRenderDrawColor Error: " << SDL_GetError() << endl;
        exit(0);
    }
}
void App::clearScreen() {
    this->setRenderColor(this->backgroundColor);
    if (SDL_RenderClear(this->renderer) != 0) {
        cout << "SDL_RenderClear Error: " << SDL_GetError() << endl;
        exit(0);
    }
}
void App::presentScreen() {
    SDL_RenderPresent(this->renderer);
}
void App::close() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    TTF_CloseFont(this->font);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}