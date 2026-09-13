#pragma once

#include <raylib.h>
#include "player.h"

typedef struct Boss
{
    Vector2 position;

    float width;
    float height;

    Rectangle body;

    int healthIcons;
    int maxHealthIcons;

    int receivedHits;
    int hitsPerIcon;

    bool active;
    bool defeated;

    bool wasHit;
} Boss;

void InitialBoss(Boss *boss)
{
    boss->position = (Vector2){10800.0f, 1390.0f};

    boss->width = 256.0f;
    boss->height = 256.0f;

    boss->body = (Rectangle){boss->position.x, boss->position.y, boss->width, boss->height};

    boss->maxHealthIcons = 10;
    boss->healthIcons = 10;

    boss->receivedHits = 0;
    boss->hitsPerIcon = 3;

    boss->active = true;
    boss->defeated = false;
    boss->wasHit = false;
}

void BossReceiveHit(Boss *boss)
{
    if(!boss->active || boss->defeated)
    {
        return;
    }

    boss->receivedHits++;

    TraceLog(LOG_INFO, "Boss received hit: %d/30", boss->receivedHits);

    if((boss->receivedHits % boss->hitsPerIcon) == 0)
    {
        boss->healthIcons--;

        TraceLog(LOG_INFO, "Boss health icons remaining: %d", boss->healthIcons);
    
        if(boss->healthIcons <= 0)
        {
            boss->healthIcons = 0;
            boss->defeated = true;
            boss->active = false;

            
            TraceLog(LOG_INFO, "BOSS DEFEATED!");
        }
    }
}

void DrawBossHealth(Boss *boss)
{
    if(!boss->active && !boss->defeated)
    {
        return;
    }

    int iconWidth = 35;
    int iconHeight = 25;
    int spacing = 8;

    int totalWidth = boss->maxHealthIcons * iconWidth + (boss->maxHealthIcons - 1) * spacing;

    int startX = GetScreenWidth() - totalWidth - 40;
    int startY = 40;

    for(int i = 0; i < boss->maxHealthIcons; i++)
    {
        Color iconColor = DARKGRAY;

        if(i < boss->healthIcons)
        {
            iconColor = RED;
        }

        DrawRectangle((startX + i * (iconWidth + spacing)), startY, iconWidth, iconHeight, iconColor);

        DrawRectangleLines((startX + i *(iconWidth + spacing)), startY, iconWidth, iconHeight, WHITE);
    }
}