#pragma once

#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;

struct Blue
{
    Rectangle body;
    Texture2D texture;

    float buoyancy;
};

struct Yellow
{
    Rectangle body;
    Texture2D texture;

    bool broken = false;
    int breakTimer = 0;
};

struct Red
{
    Rectangle body;
    Texture2D texture;
};

struct Green
{
    Rectangle body;
    Texture2D texture;
};

struct Map
{
    Texture2D background;

    Blue blue[100];
    Yellow yellow[100];
    Red red[100];
    Green green[100];

    int blueCount;
    int yellowCount;
    int redCount;
    int greenCount;
};

void LoadMap(Map &map)
{
    map.greenCount = 1;
    map.redCount = 1;
    map.blueCount = 1;
    map.yellowCount = 2;

    // Ground
    map.green[0].body = {0, 650, 1000, 70};

    // Floating platform
    map.yellow[0].body = {300, 500, 200, 40};

    // Red platform
    map.red[0].body = {650, 420, 200, 40};

    // Blue platform
    map.blue[0].body = {1000, 350, 200, 40};
    map.blue[0].buoyancy = 2.0f;

    // Yellow platform
    map.yellow[1].body = {1350, 280, 200, 40};
    map.yellow[1].broken = false;
}

void UnloadMap(Map &map)
{
    UnloadTexture(map.background);

    for(int i = 0; i < map.blueCount; i++) UnloadTexture(map.blue[i].texture);
    
    for(int i = 0; i < map.yellowCount; i++) UnloadTexture(map.yellow[i].texture);

    for(int i = 0; i < map.greenCount; i++) UnloadTexture(map.green[i].texture);

    for(int i = 0; i < map.redCount; i++) UnloadTexture(map.red[i].texture);
}

void DrawMap(Map &map)
{
    for(int i = 0; i < map.blueCount; i++)
    {
        DrawRectangleRec(map.blue[i].body, BLUE);

    }

    for(int i = 0; i < map.yellowCount; i++)
    {
        if(!map.yellow[i].broken)
        {
            DrawRectangleRec(map.yellow[i].body, YELLOW);
        }
    }

    for(int i = 0; i < map.greenCount; i++)
    {
        DrawRectangleRec(map.green[i].body, GREEN);
    }

    for(int i = 0; i < map.redCount; i++)
    {        
        DrawRectangleRec(map.red[i].body, RED);
    }
}