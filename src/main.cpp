#include <bits/stdc++.h>
#include <raylib.h>
#include "player.h"
#include "game.h"

using namespace std;

const float desiredWidth = 64.0f;
const float desiredHeight = 64.0f;

int main()
{
    InitWindow(736, 501, "demo map e kahini korbo");
    ChangeDirectory(GetApplicationDirectory());

    Player player; 
    Texture2D Demo_map = LoadTexture("Demo_map.png");
    initial_condition_of_player(player);

    // sprite er png file size e onek boro pura map parle cover kore felabe
    // for that reason eita variable rakhsi map ar sprite er size er ratio thik korte

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        update_game(player);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(Demo_map, 0, 0, WHITE);

            resize_sprite(player);

        EndDrawing();
    }

    UnloadTexture(player.Sprite);
    UnloadTexture(Demo_map);
    CloseWindow();
    
    return 0;
}