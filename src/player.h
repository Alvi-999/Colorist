#pragma once

#include <raylib.h>
#include <stdio.h>
#include "constants.h"


typedef struct Player
{
    Vector2 position;

    Vector2 velocity;

    Texture2D sprite;

    Rectangle body;
    Rectangle attack;

    float width;
    float height;

    bool facingRight;

    bool grounded;

    bool doubleJumpAvailable;

    int state;

    int hits;

    int framecount;

    bool inWater;
} Player;

//animation functions
Texture2D IdleRightAnimation(Player *player);
Texture2D IdleLeftAnimation(Player *player);
Texture2D RunRightAnimation(Player *player);
Texture2D RunLeftAnimation(Player *player);

void InitializePlayer(Player *player)
{
    player->position = (Vector2){100, 300};

    player->velocity = (Vector2){0, 0};

    player->width = 64;
    player->height = 64;

    player->body = (Rectangle){player->position.x, player->position.y, player->width, player->height};

    player->attack = (Rectangle){player->position.x, player->position.y, 50, 30};

    player->sprite = LoadTexture("idler/idler-1.png");

    player->facingRight = true;

    player->grounded = false;

    player->doubleJumpAvailable = true;

    player->state = IDLER;

    player->hits = MAX_HITS;

    player->framecount=0;
}

void InputHandling(Player *player)
{
    player->velocity.x = 0;

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

void UpdatePlayerState(Player *player)
{
    //if jumping
    int previous_state = player->state;
    if(player->velocity.y < 0)
    {
        if(player->facingRight) player->state = JUMPR;
        else player->state = JUMPL;
    }

    //falling
    else if((player->velocity.y > 0) && (!player->grounded))
    {
        player->state = FALL;
    }

    //runnin
    else if(player->velocity.x != 0)
    {
        if(player->facingRight) player->state = RUNR;
        else player->state = RUNL;
    }
    
    //idle
    else 
    {
        if(player->facingRight) player->state = IDLER;
        else player->state = IDLEL;
    }

    if (previous_state != player->state)
    {
        player->framecount = 0;
    }
}

void DrawPlayer(Player *player)
{
    //player animation goes here
    //for example, you can just run a switch here
    //depending on the state of player 
    //animation will run

    player->framecount++;
    player->framecount = (player->framecount)%60;

    //(JUST PUT THE FUNCTION TO THE ANIMATIONS HERE)
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

    Rectangle source = {0, 0, (float)player->sprite.width, (float)player->sprite.height};

    Rectangle dest = {player->position.x, player->position.y, player->width, player->height};

    DrawTexturePro(player->sprite, source, dest, (Vector2){0, 0}, 0.0f, WHITE);
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



// --------------Animation------------------------------
Texture2D RunRightAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "runr/runr-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D RunLeftAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "runl/runl-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D IdleRightAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "idler/idler-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D IdleLeftAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "idlel/idlel-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}