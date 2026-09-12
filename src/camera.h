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
    MainCamera->target = (Vector2){player->position.x, player->position.y};
    MainCamera->offset = (Vector2){(float)screenWidth/2, (float)screenHeight/2};
}

