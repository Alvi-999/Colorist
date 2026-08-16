#pragma once

#include <stdio.h>
#include <raylib.h>

typedef struct Blue
{
    Rectangle body;
    Texture2D texture;

    float buoyancy;
} Blue;

typedef struct Yellow
{
    Rectangle body;
    Texture2D texture;

    bool broken;
    int breakTimer;
} Yellow;

typedef struct Red
{
    Rectangle body;
    Texture2D texture;
} Red;

typedef struct Green
{
    Rectangle body;
    Texture2D texture;
} Green;

typedef struct Map
{
    Texture2D background;

    Green green[14];

    Red red[17];

    Blue blue[11];

    Yellow yellow[17];

    int greenCount;
    int redCount;
    int blueCount;
    int yellowCount;
} Map;


void LoadMap(Map *map)
{
    // Ground
    //-------------------- Green platform ------------------------
    //groundg1
    map->green[0].body = (Rectangle) {104, 716, 450, 360};
    map->green[1].body = (Rectangle) {1044, 1881, 428, 288};

    //groundg2
    map->green[2].body = (Rectangle) {144, 1094, 428, 292};

    //floatg1
    map->green[3].body = (Rectangle) {4874, 1094, 230, 338};
    
    //floatg2
    map->green[4].body = (Rectangle) {608, 382, 302, 369};
    map->green[5].body = (Rectangle) {3888, 1642, 202, 338};
    map->green[6].body = (Rectangle) {5436, 324, 284, 346};
    
    //flatg1
    map->green[7].body = (Rectangle) {1562, 1408, 234, 58};
    map->green[8].body = (Rectangle) {1971, 144, 243, 81};
    map->green[9].body = (Rectangle) {2758, 1886, 270, 86};
    map->green[10].body = (Rectangle) {2844, 819, 248, 68};
    map->green[11].body = (Rectangle) {3956, 945, 243, 58};
    map->green[12].body = (Rectangle) {4239, 1647, 202, 54};
    map->green[13].body = (Rectangle) {4707, 860, 230, 63};

    //-------------------- Red platform ------------------------
    //floatr1
    map->red[0].body = (Rectangle){1616, 72, 261, 450};
    map->red[1].body = (Rectangle){1845, 1472, 176, 360};
    map->red[2].body = (Rectangle){1616, 72, 261, 450};
    
    //groundr1
    map->red[3].body = (Rectangle){9, 1746, 328, 477};
    map->red[4].body = (Rectangle){5324, 1836, 302, 346};
    
    //flatr1
    map->red[5].body = (Rectangle){526, 140, 198, 54};
    map->red[6].body = (Rectangle){418, 1764, 212, 54};
    map->red[7].body = (Rectangle){2952, 1462, 256, 68};
    map->red[8].body = (Rectangle){3618, 981, 212, 63};
    map->red[9].body = (Rectangle){4576, 1904, 202, 40};
    map->red[10].body = (Rectangle){4936, 274, 220, 50};
    map->red[11].body = (Rectangle){5170, 270, 202, 45};
    map->red[12].body = (Rectangle){5458, 72, 216, 50};
    map->red[13].body = (Rectangle){5283, 1332, 189, 45};
    
    //floatr2
    map->red[14].body = (Rectangle){3416, 104, 274, 405};
    map->red[15].body = (Rectangle){3483, 1188, 256, 382};
    map->red[16].body = (Rectangle){4838, 1580, 212, 396};

    //-------------------- Blue platform ------------------------
    // floatb1
    map->blue[0].body = (Rectangle){1143, 1246, 315, 405};
    map->blue[1].body = (Rectangle){1426, 693, 356, 382};
    map->blue[2].body = (Rectangle){2628, 90, 252, 382};
    map->blue[3].body = (Rectangle){3200, 1080, 270, 315};
    map->blue[4].body = (Rectangle){3946, 324, 243, 346};
    
    //floatb2
    map->blue[5].body = (Rectangle){1998, 369, 248, 297};
    
    //flatb1
    map->blue[6].body = (Rectangle){621, 1431, 225, 86};
    map->blue[7].body = (Rectangle){3082, 1881, 256, 104};
    map->blue[8].body = (Rectangle){4059, 1458, 189, 99};
    map->blue[9].body = (Rectangle){5238, 608, 234, 99};
    map->blue[10].body = (Rectangle){5404, 1462, 194, 72};

    for (int i=0; i<11; i++)
    {
        map->blue[i].buoyancy = 2.0f;
    }

    //-------------------- Yellow platform ------------------------
    //groundy2
    map->yellow[0].body = (Rectangle){3420, 1800, 342, 369};
    
    //floaty1
    map->yellow[1].body = (Rectangle){1188, 256, 274, 356};
    map->yellow[2].body = (Rectangle){1188, 256, 274, 356};
    map->yellow[3].body = (Rectangle){1188, 256, 274, 356};
    
    //floaty2
    map->yellow[4].body = (Rectangle){1570, 1791, 207, 333};
    
    //flaty1
    map->yellow[5].body = (Rectangle){540, 832, 248, 50};
    map->yellow[6].body = (Rectangle){770, 918, 252, 45};
    map->yellow[7].body = (Rectangle){1080, 846, 266, 54};
    map->yellow[8].body = (Rectangle){760, 1220, 243, 68};
    map->yellow[9].body = (Rectangle){698, 1899, 230, 50};
    map->yellow[10].body = (Rectangle){2376, 554, 202, 54};
    map->yellow[11].body = (Rectangle){2124, 1251, 248, 68};
    map->yellow[12].body = (Rectangle){2097, 1642, 225, 58};
    map->yellow[13].body = (Rectangle){2790, 1256, 256, 76};
    map->yellow[14].body = (Rectangle){4113, 873, 220, 54};
    map->yellow[15].body = (Rectangle){4356, 778, 216, 58};
    map->yellow[16].body = (Rectangle){4158, 1220, 220, 36};

    for (int i=0; i<17; i++)
    {
        map->yellow[i].broken = false;
        map->yellow[i].breakTimer = 0;
    }

    map->greenCount = 14;
    map->redCount = 17;
    map->blueCount = 11;
    map->yellowCount = 17; 
}


void UnloadMap(Map *map)
{
    UnloadTexture(map->background);

    for(int i = 0; i < 14; i++) UnloadTexture(map->green[i].texture);
    for(int i = 0; i < 17; i++) UnloadTexture(map->red[i].texture);
    for(int i = 0; i < 11; i++) UnloadTexture(map->blue[i].texture);
    for(int i = 0; i < 17; i++) UnloadTexture(map->yellow[i].texture);
}

void DrawMap(Map *map)
{
    for(int i = 0; i < 14; i++)
    {
        DrawRectangleRec(map->green[i].body, GREEN);
    }
    for(int i = 0; i < 17; i++)
    {
        DrawRectangleRec(map->red[i].body, RED);
    }
    for(int i = 0; i < 11; i++)
    {
        DrawRectangleRec(map->blue[i].body, BLUE);
    }
    for(int i = 0; i < 17; i++)
    {
        DrawRectangleRec(map->yellow[i].body, YELLOW);
    }
}

