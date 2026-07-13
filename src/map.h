#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;

struct Blue
{
    Rectangle body;
    Texture2D texture;

    //blue things makes player float
    float buoyancy;
};

struct Yellow
{
    Rectangle body;
    Texture2D texture;

    // temporary platform
    bool broken;
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
    map.background = LoadTexture("assets/background/bg.png");

    map.blue[0].body;
    map.blue[0].texture = LoadTexture("assets/");

    map.blue[1].body;
    map.blue[1].texture = LoadTexture("assets/platforms/floatb22.png");

    map.yellow[0].body;
    map.yellow[0].texture = LoadTexture("assets/platforms/yellow1.png");

    map.yellow[1].body;
    map.yellow[1].texture = LoadTexture("assets/platforms/yellow2.png");

    map.green[0].body;
    map.green[0].texture = LoadTexture("assets/platforms/groundbg1.png");

    map.green[1].body;
    map.green[1].texture = LoadTexture("assets/platforms/groundg2.png");

    map.blueCount = 2;
    map.greenCount = 2;
    map.yellowCount = 2;
    map.redCount = 2;

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
    DrawTexture(map.background, 0, 0, WHITE);

    Rectangle source;
    Rectangle destination;

    for(int i = 0; i < map.blueCount; i++)
    {
        source = {0, 0, (float)map.blue[i].texture.width, (float)map.blue[i].texture.height};

        destination = map.blue[i].body;

        DrawTexturePro(map.blue[i].texture, source, destination, {0,0}, 0, WHITE);
    }

    for(int i = 0; i < map.yellowCount; i++)
    {
        if(!map.yellow[i].broken)
        {
            source = {0, 0, (float)map.yellow[i].texture.width, (float)map.yellow[i].texture.height};

            destination = map.yellow[i].body;

            DrawTexturePro(map.yellow[i].texture, source, destination, {0,0}, 0, WHITE);
        }
    }

    for(int i = 0; i < map.greenCount; i++)
    {
        source = {0, 0, (float)map.green[i].texture.width, (float)map.green[i].texture.height};

        destination = map.green[i].body;

        DrawTexturePro(map.green[i].texture, source, destination, {0,0}, 0, WHITE);
    }

    for(int i = 0; i < map.redCount; i++)
    {
        source = {0, 0, (float)map.red[i].texture.width, (float)map.red[i].texture.height};

        destination = map.red[i].body;

        DrawTexturePro(map.red[i].texture, source, destination, {0,0}, 0, WHITE);
    }
}