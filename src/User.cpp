#include "User.h"

#include "Machine.h"
#include "Monster.h"
// -------------------- User Class --------------------
User::User(int money) {
    this->money = money;
    cur_model_id = 1;
    menu = new BaseObject;
    menu->LoadImg("Use1.png");
    menu->setRect(0, MainScreen->SCREEN_HEIGH - menu->GetRect().h);
    int moneyVal[4] = {300, 500, 700, 1000};
    for (int i = 0; i < 4; i++) {
        machineModel.push_back(new Machine("Machine" + to_string(i) + ".png", i + 1));
        machineModel[i]->money = moneyVal[i];
    }
}
void User::RenderMenu() {
    menu->Render(NULL);
}
void User::AddMachineEvent() {
    switch (MainScreen->g_event.key.keysym.sym) {
        case SDLK_1: {
            cur_model_id = 1;
            break;
        }
        case SDLK_2: {
            cur_model_id = 2;
            break;
        }
        case SDLK_3: {
            cur_model_id = 3;
            break;
        }
        case SDLK_4: {
            cur_model_id = 4;
            break;
        }
    }
    menu->LoadImg("Use" + to_string(cur_model_id) + ".png");
}
void User::AddMachine(MachineList* machineList) {
    SDL_Rect rect = machineModel[cur_model_id - 1]->GetRect();
    SDL_GetMouseState(&rect.x, &rect.y);
    Machine* cur = machineModel[cur_model_id - 1];
    if (money > cur->money && machineList->checkDuplicate(rect) == false) {
        money -= cur->money;
        musicControl->PlaySoundEffect("set_tower");
        Machine* newMachine = cur->Clone();
        newMachine->setRect(rect.x, rect.y);
        machineList->AddMachine(newMachine);
    }
}
void User::HandleEvent(MachineList* machineList, MonsterList* monsterList) {
    if (MainScreen->g_event.type == SDL_KEYDOWN) {
        AddMachineEvent();
        if (MainScreen->g_event.key.keysym.sym == SDLK_5) {
            UseIce(monsterList);
        }
        if (MainScreen->g_event.key.keysym.sym == SDLK_6) {
            UseBomp(monsterList);
        }
    }
    if (MainScreen->g_event.type == SDL_MOUSEBUTTONDOWN) {
        AddMachine(machineList);
    }
}
void User::UseBomp(MonsterList* monsterList) {
    if (money >= bomp_cost) {
        money -= bomp_cost;
        for (int i = 0; i < monsterList->list.size(); i++) {
            if (monsterList->list[i]->IsSpawn() && monsterList->list[i]->IsLife()) {
                monsterList->list[i]->HPChange(100000);
            }
        }
    }
}
void User::UseIce(MonsterList* monsterList) {
    if (money >= ice_cost) {
        money -= ice_cost;
        for (int i = 0; i < monsterList->list.size(); i++) {
            if (monsterList->list[i]->IsSpawn())
                monsterList->list[i]->SetPause(50);
        }
    }
}
// -------------------- Tower Class --------------------
void Tower::MonsterAttack(int damage) {
    this->HP -= damage;
}
string Tower::Text() {
    string result = "HP: " + std::to_string(HP);
    return result;
}
bool Tower::isLife() {
    return this->HP > 0;
}