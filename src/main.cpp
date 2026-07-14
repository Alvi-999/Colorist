#include <bits/stdc++.h>
#include <raylib.h>
#include "player.h"
#include "game.h"
#include "map.h"

using namespace std;

int main()
{
    InitWindow(1280, 720, "Colorist");

    Player player;
    Map map;
    
    InitializePlayer(player);

    LoadMap(map);

    while(!WindowShouldClose())
    {
        UpdateGame(player, map);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawGame(player, map);

        EndDrawing();
    }

    UnloadMap(map);
    UnloadTexture(player.sprite);

    CloseWindow();
    
    return 0;
}