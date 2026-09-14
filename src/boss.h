#pragma once

#include <stdio.h>
#include <raylib.h>

typedef struct Player Player;

typedef struct Boss
{
    Vector2 position;

    float width;
    float height;

    Rectangle body;
    Rectangle attack;

    int healthIcons;
    int maxHealthIcons;

    int receivedHits;
    int hitsPerIcon;

    bool active;
    bool defeated;

    bool attacking;
    bool attackHitPlayer;

    int attackTimer;
    int attackCooldown;

    Texture2D idleSprites[12];
    int idleFrame;
    float idleTimer;
    float idleFrameTime;

    Texture2D sprite;

} Boss;

void InitialBoss(Boss *boss)
{
    boss->position = (Vector2){11000.0f, 1300.0f};

    boss->width = 256.0f;
    boss->height = 256.0f;

    boss->body = (Rectangle){boss->position.x, boss->position.y, boss->width, boss->height};

    boss->attack = (Rectangle){boss->position.x - 80, boss->position.y + 30, 80, 100};

    boss->attacking = false;
    boss->attackHitPlayer = false;

    boss->maxHealthIcons = 10;
    boss->healthIcons = 10;

    boss->receivedHits = 0;
    boss->hitsPerIcon = 3;

    boss->active = true;
    boss->defeated = false;

    boss->sprite = LoadTexture("assets/bidle/bidle-1.png");

    boss->attacking = false;
    boss->attackHitPlayer = false;

    boss->attackTimer = 0;
    boss->attackCooldown = 120;

    boss->idleSprites[0] = LoadTexture("assets/bidle/bidle-1.png");
    boss->idleSprites[1] = LoadTexture("assets/bidle/bidle-2.png");
    boss->idleSprites[2] = LoadTexture("assets/bidle/bidle-3.png");
    boss->idleSprites[3] = LoadTexture("assets/bidle/bidle-4.png");
    boss->idleSprites[4] = LoadTexture("assets/bidle/bidle-5.png");
    boss->idleSprites[5] = LoadTexture("assets/bidle/bidle-6.png");
    boss->idleSprites[6] = LoadTexture("assets/bidle/bidle-7.png");
    boss->idleSprites[7] = LoadTexture("assets/bidle/bidle-8.png");
    boss->idleSprites[8] = LoadTexture("assets/bidle/bidle-9.png");
    boss->idleSprites[9] = LoadTexture("assets/bidle/bidle-10.png");
    boss->idleSprites[10] = LoadTexture("assets/bidle/bidle-11.png");
    boss->idleSprites[11] = LoadTexture("assets/bidle/bidle-12.png");

    boss->idleFrame = 0;
    boss->idleTimer = 0.0f;
    boss->idleFrameTime = 0.15f;
}

void CheckBossCollision(Boss *boss, Player *player)
{
    if(!boss->active || boss->defeated)
    {
        return;
    }

    if(CheckCollisionRecs(player->body, boss->body))
    {
        if(player->body.x < boss->body.x)
        {
            player->position.x = boss->body.x - player->width;
        }
        else 
        {
            player->position.x = boss->body.x + boss->width;
        }

        player->body.x = player->position.x;
    }
}

void BossStartGroundSlam(Boss *boss)
{
    if(!boss->active || boss->defeated || boss->attacking)
    {
        return;
    }

    boss->attacking = true;
    boss->attackHitPlayer = false;
    boss->attackTimer = 0;

    TraceLog(LOG_INFO, "BOSS GROUND SLAM STARTED!");
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

void DrawBoss(Boss *boss)
{
    if(!boss->active || boss->defeated)
    {
        return;
    }

    if(boss->attacking && boss->attackTimer >= 36 && boss->attackTimer < 48)
    {
        DrawRectangleRec(boss->attack, RED);
        DrawRectangleLinesEx(boss->attack, 3.0f, WHITE);
    }

    Rectangle source = {
        0.0f,
        0.0f,
        (float)boss->sprite.width,
        (float)boss->sprite.height
    };

    Rectangle destination = {
        boss->position.x,
        boss->position.y,
        boss->width,
        boss->height
    };

    DrawTexturePro(
        boss->sprite,
        source,
        destination,
        (Vector2){0.0f, 0.0f},
        0.0f,
        WHITE
    );
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


void UpdateBoss(Boss *boss, Player *player)
{
    if(!boss->active || boss->defeated)
    {
        return;
    }

    boss->idleTimer += GetFrameTime();

    if(boss->idleTimer >= boss->idleFrameTime)
    {
        boss->idleTimer = 0.0f;
        boss->idleFrame++;

        if(boss->idleFrame >= 12)
        {
            boss->idleFrame = 0;
        }

        UnloadTexture(boss->sprite);

        char path[100];

        sprintf(path, "assets/bidle/bidle-%d.png", boss->idleFrame + 1);

        boss->sprite = LoadTexture(path);
    }

    boss->body.x = boss->position.x;
    boss->body.y = boss->position.y;

    if(!boss->attacking)
    {
        boss->attackCooldown--;

        if(boss->attackCooldown <= 0)
        {
            BossStartGroundSlam(boss);
        }

        return;
    }

    boss->attackTimer++;

    if(boss->attackTimer < 36)
    {
        if(player->position.x > boss->position.x)
        {
            boss->position.x += 3.0f;
        }
        else if(player->position.x < boss->position.x)
        {
            boss->position.x -= 3.0f;
        }

        boss->body.x = boss->position.x;
    }

    if(boss->attackTimer >= 36 &&
       boss->attackTimer < 48)
    {
        boss->attack = (Rectangle)
        {
            boss->position.x - 250.0f,
            boss->position.y + boss->height - 60.0f,
            boss->width + 500.0f,
            60.0f
        };

        if(!boss->attackHitPlayer &&
           CheckCollisionRecs(boss->attack, player->body))
        {
            TakeDamage(player, 1);

            boss->attackHitPlayer = true;

            TraceLog(LOG_INFO, "GROUND SLAM HIT PLAYER!");
        }
    }

    if(boss->attackTimer >= 72)
    {
        boss->attacking = false;

        boss->attackHitPlayer = false;

        boss->attackTimer = 0;

        boss->attackCooldown = 120;

        boss->attack = (Rectangle){0, 0, 0, 0};

        TraceLog(LOG_INFO, "GROUND SLAM FINISHED!");
    }
}