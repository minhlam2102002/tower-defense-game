#pragma once
#include "Screen.h"

class GameManager {
private:
    MachineList machineList;
    vector<Monster *> monsterList;
    BulletList bulletList;
    Screen MainScreen;
    BaseObject background;
    bool is_quit;
    TextObject Print_text;

public:
    void displayMenu(){};
    bool LoadBackGround(BaseObject &g_background, Screen &MainScreen) {
        bool ret = g_background.LoadImg("map.png", MainScreen);
        if (ret == false) {
            return false;
        }
        return true;
    }
    void GameInit() {
        // -------------------- Bullet init --------------------
        BulletList bulletList;
        // -------------------- Machine init --------------------
        bool is_set_machine = false;
        MachineList machineList;
        for (int i = 0; i < 100; i++) {
            Machine *a = new Machine;
            machineList.AddMachine(a);
        }
        // -------------------- Tower init --------------------
        Tower tow;
        tow.setRect(200, 200);

        // -------------------- Path init --------------------
        vector<Point> path;
        vector<Point> pathBorder;
        vector<SDL_Rect> pathRect;
        if (!DEBUG_PATH) {
            readPath(path, "GamePath.txt");
            readPath(pathBorder, "GamePathBorder.txt");
            for (int i = 0; i < pathBorder.size(); i += 2) {
                SDL_Rect rect;
                rect.x = pathBorder[i].x;
                rect.y = pathBorder[i].y;
                rect.w = pathBorder[i + 1].x - pathBorder[i].x;
                rect.h = pathBorder[i + 1].y - pathBorder[i].y;
                cout << rect.x << " " << rect.y << " " << rect.w << " " << rect.h << endl;
                pathRect.push_back(rect);
            }
        }
        // -------------------- Monster init --------------------
        vector<Monster *> ListMonster;  // Monster(int _HP, int _speed, int _spawnTime, string _file_path)
        ListMonster.push_back(new Monster(1, 1, 10, "Monster.png", MainScreen));
        ListMonster.push_back(new Monster(2, 2, 12, "Monster.png", MainScreen));
        ListMonster.push_back(new Monster(3, 3, 14, "Monster.png", MainScreen));
        ListMonster.push_back(new Monster(4, 4, 16, "Monster.png", MainScreen));
    }
    void Initial() {
        // -------------------- Game init --------------------
        MainScreen.init();
        LoadBackGround(g_background, MainScreen);
        Print_text.SetColor(TextObject::RED_TEXT);
        is_quit = false;
        GameInit();
    }
    void HandleEvent() {
        while (SDL_PollEvent(&MainScreen.g_event) != 0) {
            // Xu ly su kien chay cho den khi het su kien(theo kieu while)
            if (MainScreen.g_event.type == SDL_QUIT) {
                is_quit = true;
            }
            Devlopment(DEBUG_PATH, DEBUG_TOWER);
            // if(g_event.type == )
            // Set Machine
            /*if (is_set_machine) {
                SetMachineLocated(machineList, g_event, count);
                is_set_machine = false;
            }
            if (AddMachine(g_event, machineList, count)) {
                cout << "c" << count;
                is_set_machine = true;
            }*/
            if (is_set_machine) {
                if (MainScreen.g_event.type == SDL_MOUSEBUTTONDOWN) {
                    int xMouse, yMouse;
                    SDL_GetMouseState(&xMouse, &yMouse);
                    cout << xMouse << " " << yMouse << endl;
                    machineList.checkDuplicate(pathRect, xMouse, yMouse);
                    cout << "Set Machine Success !" << endl;
                    is_set_machine = false;
                }
            }
            if (MainScreen.g_event.type == SDL_KEYDOWN && is_set_machine == false) {
                switch (MainScreen.g_event.key.keysym.sym) {
                    case SDLK_1: {
                        cout << "Nhan phim 1";
                        machineList.getAt(MachineList::machineCount)->setLevel(1, "Machine.png", MainScreen);
                        is_set_machine = true;
                        break;
                    }
                }
            }
        }
    }
    void Update() {
        // -------------------- Game Update --------------------
        SDL_SetRenderDrawColor(MainScreen.g_screen, 255, 255, 255, 255);
        SDL_RenderClear(MainScreen.g_screen);
        // set background
        g_background.Render(MainScreen.g_screen, NULL);

        // -------------------- Tower Update --------------------
        Print_text.SetText(tow.Text());
        Print_text.LoadFromRenderText(MainScreen.g_font_text, MainScreen.g_screen);
        Print_text.RenderText(MainScreen.g_screen, MainScreen.SCREEN_WIDTH - 200, 15);
        // -------------------- Machine Update --------------------
        machineList.Update(ListMonster, bulletList, MainScreen);
        // -------------------- Bullet Update --------------------
        bulletList.Update(MainScreen);

        // -------------------- Monster Update --------------------
        for (int i = 0; i < ListMonster.size(); i++) {
            ListMonster[i]->Update(path, tow, MainScreen);
        }

        // -------------------- System Update --------------------
        Time::Increase();
        SDL_RenderPresent(MainScreen.g_screen);
        if (!DEBUG_PATH) SDL_Delay(100);
    }
    void Start() {
        //----------------------Menu Display-----------------
        if (displayMenu() == 0) {
            return;
        }
        // -------------------- Initial --------------------
        Initial();
        while (!is_quit) {
            HandleEvent();
            Update();
        }
        // -------------------- Free Memory --------------------
        g_background.Free();
        MainScreen.close();
        if (DEBUG_PATH) savePath(path);
        return 0;
    }
}