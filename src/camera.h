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

    float CameraCenterX = player->position.x;
    float CameraCenterY = player->position.y;

    // Keep the camera from going above the top of the map
    if (CameraCenterY < screenHeight / 2.0f)
    {
        CameraCenterY = screenHeight / 2.0f;
    }

    // No old 5760 X limit
    // No forced return to the main menu

    MainCamera->target = (Vector2){
        CameraCenterX,
        CameraCenterY
    };

    MainCamera->offset = (Vector2){
        screenWidth / 2.0f,
        screenHeight / 2.0f
    };
}

