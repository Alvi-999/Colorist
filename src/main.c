#include <stdio.h>
#include <raylib.h>
#include "player.h"
#include "game.h"
#include "map.h"
#include "camera.h"

int main()
{
    InitWindow(1920, 1080, "Colorist");
    SetTargetFPS(60);

    Player player;
    Map map;
    Camera2D MainCamera;
    
    InitializePlayer(&player);

    LoadMap(&map);

    InitializeCamera(&MainCamera, &player);

    while(!WindowShouldClose())
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

    UnloadMap(&map);
    UnloadTexture(player.sprite);

    CloseWindow();
    
    return 0;
}