#pragma once

#include <raylib.h>
#include <bits/stdc++.h>


// Physics constants
const float GRAVITY = 1.00f;
const float MOVE_SPEED = 3.5f;
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

    int framecount;
};

//animation functions
Texture2D IdleRightAnimation(Player &player);
Texture2D IdleLeftAnimation(Player &player);
Texture2D RunRightAnimation(Player &player);
Texture2D RunLeftAnimation(Player &player);

void InitializePlayer(Player &player)
{
    player.position = {100, 300};

    player.velocity = {0, 0};

    player.width = 64;
    player.height = 64;

    player.body = {player.position.x, player.position.y, player.width, player.height};

    player.attack = {player.position.x, player.position.y, 50, 30};

    player.sprite = LoadTexture("assets/decoration/idle_right1.png");

    player.facingRight = true;

    player.grounded = false;

    player.doubleJumpAvailable = true;

    player.state = IDLER;

    player.hits = MAX_HITS;

    player.framecount=0;
}

void InputHandling(Player &player)
{
    player.velocity.x = 0;

    if(IsKeyDown(KEY_D))
    {
        player.velocity.x = MOVE_SPEED;
        player.facingRight = true;
    }

    if(IsKeyDown(KEY_A))
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
    else if(IsKeyPressed(KEY_W) && !player.grounded && player.doubleJumpAvailable)
    {
        player.doubleJumpAvailable = false;

        player.velocity.y = JUMP_FORCE;
    }
}

void UpdatePlayerState(Player &player)
{
    //if jumping
    int previous_state = player.state;
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

    if (previous_state != player.state)
    {
        player.framecount = 0;
    }
}

void DrawPlayer(Player &player)
{
    //player animation goes here
    //for example, you can just run a switch here
    //depending on the state of player 
    //animation will run

    player.framecount++;
    player.framecount = (player.framecount)%60;

    //(JUST PUT THE FUNCTION TO THE ANIMATIONS HERE)
    switch(player.state)
    {
        case IDLER:
            player.sprite = IdleRightAnimation(player);
            break;

        case IDLEL:
            player.sprite = IdleLeftAnimation(player);
            break;

        case RUNR:
            player.sprite = RunRightAnimation(player);
            break;

        case RUNL:
            player.sprite = RunLeftAnimation(player);
            break;
        
        case JUMPL:
            break;

        case FALL:
            break;

    }

    Rectangle source = {0, 0, (float)player.sprite.width, (float)player.sprite.height};

    Rectangle dest = {player.position.x, player.position.y, player.width, player.height};

    DrawTexturePro(player.sprite, source, dest, {0, 0}, 0.0f, WHITE);
}

void UpdateMovement(Player &player)
{
    //gravity
    player.velocity.y += GRAVITY;

    //MOVE PLAYER
    player.position.x += player.velocity.x;
    player.body.x = player.position.x;

    player.position.y += player.velocity.y;
    player.body.y = player.position.y;
}



// --------------Animation------------------------------
Texture2D IdleRightAnimation(Player &player)
{
    if(player.framecount>=0 && player.framecount<5)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-1.png");
        return SpriteImage;
    }
    else if(player.framecount>=5 && player.framecount<10)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-2.png");
        return SpriteImage;
    }
    else if(player.framecount>=10 && player.framecount<15)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-3.png");
        return SpriteImage;
    }
    else if(player.framecount>=15 && player.framecount<20)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-4.png");
        return SpriteImage;
    }
    else if(player.framecount>=20 && player.framecount<25)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-5.png");
        return SpriteImage;
    }
    else if(player.framecount>=25 && player.framecount<30)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-6.png");
        return SpriteImage;
    }
    else if(player.framecount>=30 && player.framecount<35)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-7.png");
        return SpriteImage;
    }
    else if(player.framecount>=35 && player.framecount<40)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-8.png");
        return SpriteImage;
    }
    else if(player.framecount>=40 && player.framecount<45)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-9.png");
        return SpriteImage;
    }
    else if(player.framecount>=45 && player.framecount<50)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-10.png");
        return SpriteImage;
    }
    else if(player.framecount>=50 && player.framecount<55)
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-11.png");
        return SpriteImage;
    }
    else
    {
        Texture2D SpriteImage = LoadTexture("idler/idler-12.png");
        return SpriteImage;
    }
}

Texture2D IdleLeftAnimation(Player &player)
{
    if(player.framecount>=0 && player.framecount<5)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-1.png");
        return SpriteImage;
    }
    else if(player.framecount>=5 && player.framecount<10)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-2.png");
        return SpriteImage;
    }
    else if(player.framecount>=10 && player.framecount<15)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-3.png");
        return SpriteImage;
    }
    else if(player.framecount>=15 && player.framecount<20)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-4.png");
        return SpriteImage;
    }
    else if(player.framecount>=20 && player.framecount<25)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-5.png");
        return SpriteImage;
    }
    else if(player.framecount>=25 && player.framecount<30)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-6.png");
        return SpriteImage;
    }
    else if(player.framecount>=30 && player.framecount<35)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-7.png");
        return SpriteImage;
    }
    else if(player.framecount>=35 && player.framecount<40)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-8.png");
        return SpriteImage;
    }
    else if(player.framecount>=40 && player.framecount<45)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-9.png");
        return SpriteImage;
    }
    else if(player.framecount>=45 && player.framecount<50)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-10.png");
        return SpriteImage;
    }
    else if(player.framecount>=50 && player.framecount<55)
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-11.png");
        return SpriteImage;
    }
    else
    {
        Texture2D SpriteImage = LoadTexture("idlel/idlel-12.png");
        return SpriteImage;
    }
}

Texture2D RunRightAnimation(Player &player)
{
    if(player.framecount>=0 && player.framecount<5)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-1.png");
        return SpriteImage;
    }
    else if(player.framecount>=5 && player.framecount<10)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-2.png");
        return SpriteImage;
    }
    else if(player.framecount>=10 && player.framecount<15)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-3.png");
        return SpriteImage;
    }
    else if(player.framecount>=15 && player.framecount<20)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-4.png");
        return SpriteImage;
    }
    else if(player.framecount>=20 && player.framecount<25)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-5.png");
        return SpriteImage;
    }
    else if(player.framecount>=25 && player.framecount<30)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-6.png");
        return SpriteImage;
    }
    else if(player.framecount>=30 && player.framecount<35)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-7.png");
        return SpriteImage;
    }
    else if(player.framecount>=35 && player.framecount<40)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-8.png");
        return SpriteImage;
    }
    else if(player.framecount>=40 && player.framecount<45)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-9.png");
        return SpriteImage;
    }
    else if(player.framecount>=45 && player.framecount<50)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-10.png");
        return SpriteImage;
    }
    else if(player.framecount>=50 && player.framecount<55)
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-11.png");
        return SpriteImage;
    }
    else
    {
        Texture2D SpriteImage = LoadTexture("runr/runr-12.png");
        return SpriteImage;
    }
}

Texture2D RunLeftAnimation(Player &player)
{
    if(player.framecount>=0 && player.framecount<5)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-1.png");
        return SpriteImage;
    }
    else if(player.framecount>=5 && player.framecount<10)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-2.png");
        return SpriteImage;
    }
    else if(player.framecount>=10 && player.framecount<15)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-3.png");
        return SpriteImage;
    }
    else if(player.framecount>=15 && player.framecount<20)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-4.png");
        return SpriteImage;
    }
    else if(player.framecount>=20 && player.framecount<25)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-5.png");
        return SpriteImage;
    }
    else if(player.framecount>=25 && player.framecount<30)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-6.png");
        return SpriteImage;
    }
    else if(player.framecount>=30 && player.framecount<35)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-7.png");
        return SpriteImage;
    }
    else if(player.framecount>=35 && player.framecount<40)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-8.png");
        return SpriteImage;
    }
    else if(player.framecount>=40 && player.framecount<45)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-9.png");
        return SpriteImage;
    }
    else if(player.framecount>=45 && player.framecount<50)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-10.png");
        return SpriteImage;
    }
    else if(player.framecount>=50 && player.framecount<55)
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-11.png");
        return SpriteImage;
    }
    else
    {
        Texture2D SpriteImage = LoadTexture("runl/runl-12.png");
        return SpriteImage;
    }
}