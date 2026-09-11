#pragma once

#include <raylib.h>
#include <stdio.h>
#include "constants.h"
#include "grappling.h"

typedef struct Player
{
    Vector2 position;
    Vector2 spawnPosition;
    
    Vector2 velocity;
    
    Texture2D sprite;
    
    Rectangle body;
    Rectangle attack;
    
    float width;
    float height;
    
    bool facingRight;
    bool grounded;
    bool doubleJumpAvailable;
    bool inWater;
    
    int state;
    
    int hits;
    int framecount;
    
    // Combat
    int attackTimer;
    bool defending;

    GrapplingHook hook;
} Player;

#include "animation.h"

void StartAttack(Player *player);
void StartDefence(Player *player);
void TakeDamage(Player *player, int damage);
void InitializePlayer(Player *player);
void InputHandling(Player *player);
void UpdatePlayerState(Player *player);
void UpdateMovement(Player *player);
void DrawPlayer(Player *player);



//animation functions
Texture2D IdleRightAnimation(Player *player);
Texture2D IdleLeftAnimation(Player *player);
Texture2D RunRightAnimation(Player *player);
Texture2D RunLeftAnimation(Player *player);

void InitializePlayer(Player *player)
{
    player->position = (Vector2){546, 76};
    player->spawnPosition = (Vector2){546, 76};

    player->position = player->spawnPosition;
    
    player->velocity = (Vector2){0, 0};

    player->width = 64;
    player->height = 64;

    player->hook.position = player->position;
    player->hook.direction = (Vector2){0.0f, 0.0f};
    player->hook.attachPoint = (Vector2){0.0f, 0.0f};
    player->hook.distanceTravelled = 0.0f;
    player->hook.attached = false;
    player->hook.state = HOOK_IDLE;

    player->body = (Rectangle){
        player->position.x,
        player->position.y,
        player->width,
        player->height
    };

    player->attack = (Rectangle){
        player->position.x,
        player->position.y,
        50,
        30
    };

    player->sprite = LoadTexture("idler/idler-1.png");

    player->facingRight = true;
    player->grounded = false;
    player->doubleJumpAvailable = true;

    player->state = IDLER;
    player->hits = MAX_HITS;
    player->framecount = 0;
}

void RespawnPlayer(Player *player)
{
    player->position = player->spawnPosition;

    player->body.x = player->position.x;
    player->body.y = player->position.y;

    player->velocity = (Vector2){0, 0};

    player->hits = MAX_HITS;

    player->grounded = false;
    player->doubleJumpAvailable = true;
    player->inWater = false;

    player->defending = false;
    player->attackTimer = 0;

    player->state = IDLER;
}

void InputHandling(Player *player)
{
    if(player->state == DEATH)
    {
        return;
    }

    player->velocity.x = 0;

    if(player->state == ATTACK)
    {
        return;
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        StartAttack(player);
        return;
    }

    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        StartDefence(player);
        return;
    }

    if(IsKeyDown(KEY_D))
    {
        player->velocity.x = MOVE_SPEED;
        player->facingRight = true;
    }

    if(IsKeyDown(KEY_A))
    {
        player->velocity.x = -MOVE_SPEED;    
        player->facingRight = false;
    }

    //first jump
    if(IsKeyPressed(KEY_W) && player->grounded && (!player->inWater))
    {
        player->velocity.y = JUMP_FORCE;

        player->grounded = false;
    }
    
    //the second jump
    else if(IsKeyPressed(KEY_W) && (!player->grounded) && player->doubleJumpAvailable && (!player->inWater))
    {
        player->doubleJumpAvailable = false;

        player->velocity.y = JUMP_FORCE;
    }
}

void DrawPlayer(Player *player)
{
    // Player animation goes here
    player->framecount++;
    player->framecount = player->framecount % 60;

    switch(player->state)
    {
        case 0: //idlel
            UnloadTexture(player->sprite);
            player->sprite = IdleLeftAnimation(player);
            break;

        case 1: //idler
            UnloadTexture(player->sprite);
            player->sprite = IdleRightAnimation(player);
            break;

        case 2: //runl
            UnloadTexture(player->sprite);
            player->sprite = RunLeftAnimation(player);
            break;

        case 3: //runr
            UnloadTexture(player->sprite);
            player->sprite = RunRightAnimation(player);
            break;
        
        case 4: //jump
            break;

        case 5: //fall
            break;

    }

    Rectangle source =
    {
        0,
        0,
        (float)player->sprite.width,
        (float)player->sprite.height
    };

    Rectangle dest =
    {
        player->position.x,
        player->position.y,
        player->width,
        player->height
    };

    DrawTexturePro(
        player->sprite,
        source,
        dest,
        (Vector2){0, 0},
        0.0f,
        WHITE
    );
}


void UpdateMovement(Player *player)
{
    //gravity
    player->velocity.y += GRAVITY;

    //MOVE PLAYER
    player->position.x += player->velocity.x;
    player->body.x = player->position.x;

    player->position.y += player->velocity.y;
    player->body.y = player->position.y;
}

void UpdatePlayerState(Player *player)
{
    int previous_state = player->state;

    if(player->velocity.y < 0)
    {
        if(player->facingRight) player->state = JUMPR;
        else player->state = JUMPL;
    }
    else if((player->velocity.y > 0) && (!player->grounded))
    {
        player->state = FALL;
    }
    else if(player->velocity.x != 0)
    {
        if(player->facingRight) player->state = RUNR;
        else player->state = RUNL;
    }
    else 
    {
        if(player->facingRight) player->state = IDLER;
        else player->state = IDLEL;
    }

    if(previous_state != player->state)
    {
        player->framecount = 0;
    }
}