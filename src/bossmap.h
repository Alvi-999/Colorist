#pragma once

#include "raylib.h"

Texture2D Boss_Map_Background;
Texture2D Boss_Map_Ground;

void InitializeBossMap()
{
    Boss_Map_Background = LoadTexture("assets/mapping.png");
    Boss_Map_Ground = LoadTexture("assets/bossground.png");
    Rectangle Boss_Map_Ground_Body = { 0, 1925, 5760, 235 };
}

void DrawBossMap()
{
    BeginDrawing();
        DrawTexture(Boss_Map_Background, 0, 0, WHITE);
        DrawTexture(Boss_Map_Ground, 0, 1925, WHITE);
    EndDrawing();
}