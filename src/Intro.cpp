#include "Intro.h"

void Intro::render() {
    App* app = App::getInstance();
    BaseObject background = BaseObject("../assets/imgs/backgrounds/intro.png", {0, 0, App::SCREEN_WIDTH, App::SCREEN_HEIGHT});

    BaseObject startButton, quitButton;
    startButton.rect.w = 100;
    startButton.rect.h = 50;
    startButton.rect.x = (App::SCREEN_WIDTH - startButton.rect.w) / 2;
    startButton.rect.y = (App::SCREEN_HEIGHT - startButton.rect.h) / 2 - 50;
    startButton.loadImage("../assets/imgs/buttons/greyStartButton.png");

    quitButton.rect.w = 100;
    quitButton.rect.h = 50;
    quitButton.rect.x = (App::SCREEN_WIDTH - quitButton.rect.w) / 2;
    quitButton.rect.y = (App::SCREEN_HEIGHT - startButton.rect.h) / 2 + 50;
    quitButton.loadImage("../assets/imgs/buttons/GreyQuitButton.png");


    int opt = -1;

    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                app->close();
                break;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_Point pos = { event.button.x, event.button.y };
                if (SDL_PointInRect(&pos, &startButton.rect)) {
                    cout << "Start Button Pressed\n";
                    break;
                }
                if (SDL_PointInRect(&pos, &quitButton.rect)) {
                    cout << "Quit Button Pressed\n";
                    break;
                }
            } else if(event.type == SDL_MOUSEMOTION) {
                SDL_Point pos = { event.button.x, event.button.y };
                if (SDL_PointInRect(&pos, &startButton.rect)) {
                    startButton.loadImage("../assets/imgs/buttons/startButton.png");
                } else {
                    startButton.loadImage("../assets/imgs/buttons/greyStartButton.png");
                }
                if (SDL_PointInRect(&pos, &quitButton.rect)) {
                    quitButton.loadImage("../assets/imgs/buttons/quitButton.png");
                } else {
                    quitButton.loadImage("../assets/imgs/buttons/GreyQuitButton.png");
                }
            };
        }

        app->clearScreen();
        background.render();
        startButton.render();
        quitButton.render();
        app->presentScreen();
    }
};