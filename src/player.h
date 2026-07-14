#pragma once

#include <raylib.h>
#include <bits/stdc++.h>


// Physics constants
const float GRAVITY = 0.8f;
const float MOVE_SPEED = 5.0f;
const float JUMP_FORCE = -18.0f;

// Player states
const int IDLEL = 0;
const int IDLER = 1;
const int RUNL = 2;
const int RUNR = 3;
const int JUMPL = 4;
const int JUMPR = 5;
const int FALL = 6;
const int ATTACK = 7;
const int DASH = 8;

const int MAX_HITS = 5;


struct Player
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
};

void InitializePlayer(Player &player)
{
    player.position = {100, 300};

    player.velocity = {0, 0};

    player.width = 64;
    player.height = 64;

    player.body = {player.position.x, player.position.y, player.width, player.height};

    player.attack = {player.position.x, player.position.y, 50, 30};

    player.sprite = LoadTexture("assets/player/idle_right.png");

    player.facingRight = true;

    player.grounded = false;

    player.doubleJumpAvailable = true;

    player.state = IDLER;

    player.hits = MAX_HITS;
}

void InputHandling(Player &player)
{
    player.velocity.x = 0;

    if(IsKeyDown(KEY_D))
    {
        player.velocity.x = MOVE_SPEED;
        player.facingRight = true;
    }

    if(IsKeyDown(KEY_D))
    {
        player.velocity.x = -MOVE_SPEED;    
        player.facingRight = false;
    }

    //first jump
    if(IsKeyPressed(KEY_W) && player.grounded)
    {
        player.velocity.y = JUMP_FORCE;

        player.grounded = false;
    }
    
    //the second jump
    else if(IsKeyPressed(KEY_UP) && !player.grounded && player.doubleJumpAvailable)
    {
        player.doubleJumpAvailable = false;

        player.velocity.y = JUMP_FORCE;
    }
}

void UpdatePlayerState(Player &player)
{
    //if jumping
    if(player.velocity.y < 0)
    {
        if(player.facingRight) player.state = JUMPR;
        else player.state = JUMPL;
    }

    //falling
    else if((player.velocity.y > 0) and !player.grounded)
    {
        player.state = FALL;
    }

    //runnin
    else if(player.velocity.x != 0)
    {
        if(player.facingRight) player.state = RUNR;
        else player.state = RUNL;
    }
    
    //idle
    else 
    {
        if(player.facingRight) player.state = IDLER;
        else player.state = IDLEL;
    }
}

void DrawPlayer(Player &player)
{
    Rectangle source = {0, 0, (float)player.sprite.width, (float)player.sprite.height};

    if(!player.facingRight)
    {
        source.width *= -1;
    }

    Rectangle destination = {player.position.x, player.position.y, player.width, player.height};

    DrawTexturePro(player.sprite, source, destination, {0, 0}, 0, WHITE);
}

void UpdateMovement(Player &player)
{
    player.velocity.y += GRAVITY;

    //MOVE PLAYER
    player.position.x += player.velocity.x;
    player.position.y += player.velocity.y;

    //update hitbox
    player.body.x = player.position.x;
    player.body.y = player.position.y;
}