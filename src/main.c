#include <stdio.h>
#include <raylib.h>
#include "player.h"
#include "game.h"
#include "map.h"
#include "camera.h"
#include "menu.h"
#include "intro.h"

int main()
{
    InitWindow(1920, 1080, "Colorist");
    SetTargetFPS(60);

    PlayIntro();

    InitializeMenu();

    Player player;
    Map map;
    Camera2D MainCamera;
    
    InitializePlayer(&player);

    LoadMap(&map);

    InitializeCamera(&MainCamera, &player);

    while(!WindowShouldClose())
    {

        if (Menu_State == MENU_MAIN)
        {
            UpdateMenu();

            if (Menu_State != MENU_MAIN)
            {
                continue;
            }

            BeginDrawing();
                DrawMenu();
            EndDrawing();
        }
        else if (Menu_State == MENU_RULEBOOK) //Since ekhono rulebook design hoynai, oke main menu tei rakhbo
        {
            BeginDrawing();
                DrawMenu();
            EndDrawing();
        }
        else if (Menu_State == MENU_GAME)
        {
            UpdateGame(&player, &map);

            UpdateMainCamera(&MainCamera, &player);

            BeginDrawing();

            ClearBackground(BLACK);

            BeginMode2D(MainCamera);
                DrawGame(&player, &map);
            EndMode2D();

            EndDrawing();
        }
        else if (Menu_State == MENU_QUIT)
        {
            UnloadAllMenuTexture();
            break;
        }
    }

    UnloadMap(&map);
    UnloadTexture(player.sprite);

    CloseWindow();
    
    return 0;
}