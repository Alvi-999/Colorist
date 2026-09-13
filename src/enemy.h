#pragma once 

#include <raylib.h>
#include "constants.h"
#include "player.h"
#include "math.h"

typedef struct Boss
{
    Vector2 position;
    Vector2 spawnPosition;
    Vector2 velocity;

    float width;
    float height;

    Rectangle body;
    Rectangle attack;

    int health;
    int maxHealth;
    
    bool facingRight;
    bool defending;
    
    float speed;

    int state;
    int previousState;

    int attackTimer;
    int attackCooldown;

    int hurtTimer;

    int framecount;
    Texture2D sprite;
} Boss;

void InitializeBoss(Boss *boss, Vector2 spawnPosition)
{
    boss->position = spawnPosition;
    boss->spawnPosition = spawnPosition;

    boss->velocity = (Vector2){0.0f, 0.0f};

    boss->width = 256.0f;
    boss->height = 256.0f;

    boss->body = (Rectangle){boss->position.x, boss->position.y, boss->width, boss->height};

    boss->attack = (Rectangle){0, 0, 0, 0};

    boss->maxHealth = BOSS_MAX_HEALTH_BARS * BOSS_HITS_PER_BAR;

    boss->health = boss->maxHealth;

    boss->facingRight = false;
    
    boss->state = BOSS_IDLE;
    boss->previousState = BOSS_IDLE;
    
    boss->attackTimer = 0;

    boss->framecount = 0;

    // boss->sprite = ;
}

void UpdateBossAI(Boss *boss, Player *player)
{
    if (boss->health <= 0)
    {
        boss->state = BOSS_DEATH;
        return;
    }

    if (boss->hurtTimer > 0)
    {
        boss->state = BOSS_STUNNED;
        return;
    }

    float distanceX = player->position.x - boss->position.x;

    float absoluteDistanceX = fabsf(distanceX);

    if (distanceX > 0)
    {
        boss->facingRight = true;
    }
    else if (distanceX < 0)
    {
        boss->facingRight = false;
    }

    if (absoluteDistanceX > BOSS_CHASE_DISTANCE)
    {
        boss->state = BOSS_IDLE;
    }
    else if (absoluteDistanceX <= BOSS_STOP_DISTANCE)
    {
        boss->state = BOSS_ATTACK;
    }
    else
    {
        boss->state = BOSS_RUN;
    }
}

void UpdateBossMovement(Boss *boss, Player *player)
{
    if (boss->state != BOSS_RUN)
    {
        boss->velocity.x = 0.0f;
        return;
    }

    if (player->position.x > boss->position.x)
    {
        boss->velocity.x = BOSS_SPEED;
        boss->facingRight = true;
    }
    else if (player->position.x < boss->position.x)
    {
        boss->velocity.x = -BOSS_SPEED;
        boss->facingRight = false;
    }
    else
    {
        boss->velocity.x = 0.0f;
    }

    boss->position.x += boss->velocity.x;

    boss->body.x = boss->position.x;
    boss->body.y = boss->position.y;
}

void BossTakeDamage(Boss *boss, int damage)
{
   if(boss->state == BOSS_DEATH || boss->state == BOSS_BLOCK)
   {
        return;
   } 

   boss->health -= damage;

   if(boss->health <= 0)
   {
        boss->health = 0;
        boss->state = BOSS_DEATH;
   }   
}

void UpdateBossBlock(Boss *boss, Player *player)
{
    if(boss->state == BOSS_DEATH || boss->state == BOSS_STUNNED)
    {
        return;
    }

    float distanceX = player->position.x - boss->position.x;
    float absoluteDistanceX = fabsf(distanceX);

    if(player->state == ATTACK && absoluteDistanceX <= BOSS_STOP_DISTANCE)
    {
        boss->state = BOSS_BLOCK;
        boss->velocity.x = 0.0f;
        return;
    }

    if(boss->state == BOSS_BLOCK)
    {
        boss->state = BOSS_IDLE;
    }
}