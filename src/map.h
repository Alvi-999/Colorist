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
    map.background;

    map.blue[0].body;
    map.blue[0].texture;

    map.blue[1].body;
    map.blue[1].texture;

    map.yellow[0].body;
    map.yellow[0].texture;

    map.yellow[1].body;
    map.yellow[1].texture;

    map.green[0].body;
    map.green[0].texture;

    map.green[1].body;
    map.green[1].texture;

    map.blueCount = 2;
    map.greenCount = 2;
    map.yellowCount = 2;
    map.redCount = 2;

}

void DrawMap(Map &map)
{
    DrawTexture(map.background, 0, 0, WHITE);

    for(int i = 0; i < map.blueCount; i++)
    {

    }
}