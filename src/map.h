#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;

struct Platform
{
    Rectangle body;
    Texture2D texture;
};

struct Map
{
    Texture2D background;

    Platform platforms[100];

    int platform_count;
};

void LoadMap(Map &map)
{
    map.background = LoadTexture("assets/background/bg.png");

    map.platform_count = 3;

    map.platforms[0].body = {0, 430, 250, 70};
}

void DrawMap(Map &map)
{
    DrawTexture(map.background, 0, 0, WHITE);

    for(int i = 0; i < map.platform_count; i++)
    {

    }
}