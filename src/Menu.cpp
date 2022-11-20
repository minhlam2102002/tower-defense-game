#include "Menu.h";
bool XYInRect(SDL_Rect box, int xx, int yy)
{
    if ((box.x < xx) && (box.x + box.w > xx) && (box.y < yy) && (box.y + box.h > yy)) return true;
    return false;
};
int displayMenu (string BG_file_path)
{
    Screen MainScreen;
	MainScreen.InitData();
    bool is_quit = false;
    SDL_Texture* background = IMG_LoadTexture(MainScreen.g_screen, BG_file_path.c_str());
    string StartButtonPath = "resource/StartButtonGreyed.png";
    SDL_Texture* StartButton = IMG_LoadTexture(MainScreen.g_screen, StartButtonPath.c_str());
    string QuitButtonPath = "resource/QuitButton.png";
    SDL_Texture* QuitButton = IMG_LoadTexture(MainScreen.g_screen, QuitButtonPath.c_str());
    SDL_Rect StartButton_hitbox;
    SDL_Rect QuitButton_hitbox;
    SDL_Rect backgroundLocation;

    StartButton_hitbox.w = 100;
    StartButton_hitbox.h = 50;
    StartButton_hitbox.x = (MainScreen.SCREEN_WIDTH - StartButton_hitbox.w) / 5;
    StartButton_hitbox.y = (MainScreen.SCREEN_HEIGH - StartButton_hitbox.h) * 60 / 100;

    QuitButton_hitbox.w = 100;
    QuitButton_hitbox.h = 50;
    QuitButton_hitbox.x = (MainScreen.SCREEN_WIDTH - QuitButton_hitbox.w) / 5;
    QuitButton_hitbox.y = StartButton_hitbox.y + StartButton_hitbox.h*3/2;

    backgroundLocation.x = 0;
    backgroundLocation.y = 0;
    backgroundLocation.w = MainScreen.SCREEN_WIDTH;
    backgroundLocation.h = MainScreen.SCREEN_HEIGH;
    while (!is_quit) {
        while (SDL_PollEvent(&MainScreen.g_event) != 0) {
            if (MainScreen.g_event.type == SDL_QUIT) {
                is_quit = true;
            }
            else
                if (MainScreen.g_event.type == SDL_MOUSEBUTTONDOWN) // if the user clicked a mousebutton
                {
                    if (XYInRect(StartButton_hitbox, MainScreen.g_event.button.x, MainScreen.g_event.button.y)) // so if the mouse-click is on the button
                    {
                        cout << "Start Button Pressed\n";
                        MainScreen.close();
                        return 1;
                    }
                    if (XYInRect(QuitButton_hitbox, MainScreen.g_event.button.x, MainScreen.g_event.button.y)) // so if the mouse-click is on the button
                    {
                        cout << "Quit Button Pressed\n";
                        MainScreen.close();
                        return 0;
                    }
                }
                else
                {
                    if (XYInRect(StartButton_hitbox, MainScreen.g_event.button.x, MainScreen.g_event.button.y))
                    {
                        StartButtonPath = "resource/StartButton.png";
                        StartButton = IMG_LoadTexture(MainScreen.g_screen, StartButtonPath.c_str());
                    }
                    else
                    {
                        StartButtonPath = "resource/StartButtonGreyed.png";
                        StartButton = IMG_LoadTexture(MainScreen.g_screen, StartButtonPath.c_str());
                    };
                    if (XYInRect(QuitButton_hitbox, MainScreen.g_event.button.x, MainScreen.g_event.button.y))
                    {
                        QuitButtonPath = "resource/QuitButton.png";
                        QuitButton = IMG_LoadTexture(MainScreen.g_screen, QuitButtonPath.c_str());
                    }
                    else
                    {
                        QuitButtonPath = "resource/QuitButtonGreyed.png";
                        QuitButton = IMG_LoadTexture(MainScreen.g_screen, QuitButtonPath.c_str());
                    }
                };
        }

        SDL_RenderClear(MainScreen.g_screen);
        SDL_RenderCopy(MainScreen.g_screen, background, NULL, &backgroundLocation);

        //SDL_RenderFillRect(MainScreen.g_screen, &r);
        SDL_RenderCopy(MainScreen.g_screen, StartButton, nullptr, &StartButton_hitbox);
        SDL_RenderCopy(MainScreen.g_screen, QuitButton, nullptr, &QuitButton_hitbox);

        // Render the rect to the screen
        SDL_RenderPresent(MainScreen.g_screen);

        // Wait for 0.3 sec
        SDL_Delay(100);
    }
    MainScreen.close();

    return 0;
};