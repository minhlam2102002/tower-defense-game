#pragma once
#include "App.h"
#include "Intro.h"
#include "Machine.h"
#include "Monster.h"
#include "Bullet.h"

class Game {
private:
    vector<Machine*> machines;
    vector<Machine*> machineModels;
    vector<Monster*> monsters;
    vector<Bullet*> bullets;
    BaseObject* map;
    App* app;
    Intro* menu;
    bool isRunning;
    int isPlacingMachine;
private:
    void eventHandler() {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                this->isRunning = false;
                break;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_Point pos = { event.button.x, event.button.y };
                if (this->isPlacingMachine == -1) {
                    // for (int i = 0; i < this->machineModels.size(); i++) {
                    //     if (SDL_PointInRect(&pos, &this->machineModels[i]->rect)) {
                    //         this->isPlacingMachine = i;
                    //         break;
                    //     }
                    // }
                } else {
                    // this->isPlacingMachine = false;
                    // this->machines.push_back(new Machine(*this->machineModels[0]));
                    // this->machines.back()->rect.x = pos.x;
                    // this->machines.back()->rect.y = pos.y;
                }
            }
        }
    }
    void renderMonsterModel() {
        for (int i = 0; i < this->machineModels.size(); i++) {
            this->machineModels[i]->render();
        }
    }
    void renderMonsters() {
        for(int i = 0; i < monsters.size(); i++) {
            monsters[i]->render();
        }
    }
    void renderMachines() {
        for (int i = 0; i < machines.size(); i++) {
            machines[i]->render();
        }
    }
    void renderBullets() {
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i]->render();
        }
    }

public:
    Game() {
        this->isRunning = true;
        this->isPlacingMachine = -1;
        this->app = App::getInstance();
        this->map = new BaseObject("../assets/imgs/maps/map0.png", {0, 0, App::SCREEN_WIDTH, App::SCREEN_HEIGHT});

        SDL_Rect rect = {0, 0, 50, 50};
        Machine* machine0 = new Machine("../assets/imgs/machines/machine0.png", rect);
        rect.x += 50;
        Machine* machine1 = new Machine("../assets/imgs/machines/machine1.png", rect);
        rect.x += 50;
        Machine* machine2 = new Machine("../assets/imgs/machines/machine2.png", rect);
        rect.x += 50;
        Machine* machine3 = new Machine("../assets/imgs/machines/machine3.png", rect);
        this->machineModels.push_back(machine0);
        this->machineModels.push_back(machine1);
        this->machineModels.push_back(machine2);
        this->machineModels.push_back(machine3);

    }
    void mainLoop() {
        while (isRunning) {
            eventHandler();
            this->app->clearScreen();

            this->map->render();
            
            renderMonsterModel();
            renderMonsters();
            renderMachines();
            renderBullets();       

            this->app->presentScreen();
        }
        this->app->close();
    }
};