#pragma once

#include <raylib.h>
#include "player.h"
#include "menu.h"

void InitializeCamera(Camera2D *MainCamera, Player *player)
{
    float screenWidth = (float)GetScreenWidth();
    float screenHeight = (float)GetScreenHeight();
    MainCamera->target = (Vector2){player->position.x, player->position.y};
    MainCamera->offset = (Vector2){(float)screenWidth/2, (float)screenHeight/2};
    MainCamera->rotation = 0;
    MainCamera->zoom = 1;
}

void UpdateMainCamera(Camera2D *MainCamera, Player *player)
{
    if(Menu_State == MENU_GAME)
    {
        float screenWidth = (float)GetScreenWidth();
        float screenHeight = (float)GetScreenHeight();

        float CameraCenterX = max(player->position.x, 1920.0/2);
        CameraCenterX = min(CameraCenterX, 5760.0-(1920.0/2));

        float CameraCenterY = max(player->position.y, 1080.0/2);

        if(CameraCenterY > 2160)
        {
            player->position.x = 546;
            player->position.y = 76;
            Menu_State = MENU_MAIN;
        }

        MainCamera->target = (Vector2){CameraCenterX, CameraCenterY};
        MainCamera->offset = (Vector2){(float)screenWidth/2, (float)screenHeight/2};
    }
    else if(Menu_State == MENU_BOSS)
    {
        float screenWidth = (float)GetScreenWidth();
        float screenHeight = (float)GetScreenHeight();

        float CameraCenterX = min(player->position.x, 14800);
        CameraCenterX = max(CameraCenterX, 10960);
        float CameraCenterY = 1245; //705 + (1080/2)

        MainCamera->target = (Vector2){CameraCenterX, CameraCenterY};
        MainCamera->offset = (Vector2){(float)screenWidth/2, (float)screenHeight/2};
    }
}



