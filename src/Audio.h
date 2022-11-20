#pragma once
#include "App.h"

class Audio {
private:
    Mix_Music* background_music = NULL;
    Mix_Chunk* monster_die = NULL;
    Mix_Chunk* set_tower = NULL;
    Mix_Chunk* win_game = NULL;
    Mix_Chunk* lose_game = NULL;

public:
    void Init() {
        // initializes  the subsystems
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            printf("Unable to initialize SDL %s\n", SDL_GetError());
            return;
        }
        // Init SDL_mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
            printf("%s", Mix_GetError());
            return;
        }
        // Load Music
        background_music = Mix_LoadMUS("background_music.mp3");
        // Load Sound Effect
        monster_die = Mix_LoadWAV("monster_die.wav");
        set_tower = Mix_LoadWAV("set_tower.wav");
        win_game = Mix_LoadWAV("win_game.wav");
        lose_game = Mix_LoadWAV("lose_game.wav");
        if (!background_music || !monster_die || !set_tower || !win_game || !lose_game) {
            cout << Mix_GetError() << endl;
        }
    }
    void PlaybackgroundMusic() {
        if (!Mix_PlayingMusic())
            Mix_PlayMusic(background_music, -1);
    }
    void PlaySoundEffect(string sound) {
        Mix_Chunk* chunk = NULL;
        int chanel = -1;
        if (sound == "monster_die") chunk = monster_die, chanel = 1;
        if (sound == "set_tower") chunk = set_tower, chanel = 2;
        if (sound == "win_game") chunk = win_game, chanel = 3;
        if (sound == "lose_game") chunk = lose_game, chanel = 4;
        if (chunk && !Mix_Playing(-1))
            Mix_PlayChannel(chanel, chunk, 0);
    }
    void Free() {
        Mix_CloseAudio();
    }
};