#pragma once

#include <raylib.h>
#include "player.h"

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

