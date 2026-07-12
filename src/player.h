#pragma once
#include <raylib.h>
#include <bits/stdc++.h>

using namespace std;

const float GRAVITY = 0.8f;
const float MOVE_SPEED = 3.0f;
const float JUMP_FORCE = -12.0f;
// ground er position ta apatoto demo_map er jonno rakhsi. Main map er hishab alada and aro valoi kechal ase arki.
const float GROUND_Y = 431.0f; //floor er y-position, screen onujayi change hobe


typedef struct
{
    float x;
    float y;
    Vector2 velocity;
    bool isGrounded; // mati te ache kina check korar jonno
    Texture2D Sprite;
    int direction; //1 hoile right e takay thakbe, -1 hoile left e takay thakbe

    // sprite er png file size e onek boro pura map parle cover kore felabe
    // for that reason eita variable rakhsi map ar sprite er size er ratio thik korte
    float desiredWidth;
    float desiredHeight;
} Player;

//-----------------global variable for double jump----------------
    bool doubleJumpAvailable;
    clock_t airTimeStart=0;


// -----------------------initially player er condition bujhay------------------------------------------
void initial_condition_of_player(Player &player)
{
    player.x = 200;
    player.y = GROUND_Y;
    player.velocity.x = 0;
    player.velocity.y = 0;
    player.isGrounded = true;
    player.direction = 1;

    player.Sprite = LoadTexture("idle_right1.png");

    player.desiredHeight = 64.0f;
    player.desiredWidth = 64.0f;
}

//------------- character er size mapmoto thik kore -----------------------------
void resize_sprite(Player &player)
{
    //eta represent kore actual image ta
    Rectangle boro_sprite = {
        0.0f,
        0.0f, 
        (float) player.direction * player.Sprite.width,
        (float) player.Sprite.height
    };

    //map er jonno size kora sprite ta ekhane thakbe
    Rectangle choto_sprite = {
        player.x,
        player.y,
        player.desiredWidth,
        player.desiredHeight
    };

    Vector2 origin = { player.desiredHeight, player.desiredWidth };

    DrawTexturePro(player.Sprite, boro_sprite, choto_sprite, origin, 0.0f, WHITE);
}


// --------------------------------------------------- UPDATES MOVEMENT OF A PLAYER -----------------------------------------------------------

// Follows WASD

void updatemovement(Player &player)
{
    // ---------- Horizontal movement ----------
    if(IsKeyDown(KEY_A))
    {
        player.x -= MOVE_SPEED;
        player.direction = -1;
    }
    else if(IsKeyDown(KEY_D))
    {
        player.x += MOVE_SPEED;
        player.direction = 1;
    }

    // ---------- Jump ----------
    // Shudhu mati te thakle jump korte parbe (no double jump)
    if(IsKeyPressed(KEY_W) && player.isGrounded)
    {
        player.velocity.y = JUMP_FORCE;
        player.isGrounded = false;

        airTimeStart = clock();
    }

    // ---------- Gravity (every frame) ----------
    player.velocity.y += GRAVITY;
    player.y += player.velocity.y;

    // ---------- Ground collision ----------
    if(player.y >= GROUND_Y)
    {
        player.y = GROUND_Y;      // mati te atke jabe, niche namte parbe na
        player.velocity.y = 0;
        player.isGrounded = true;

        doubleJumpAvailable = true;
        airTimeStart = 0;
    }

    // ------------- Double Jump ---------------
    int airtimeinMS = ( (clock()-airTimeStart) * 1000 ) / CLOCKS_PER_SEC ;
    if(IsKeyPressed(KEY_W) && airtimeinMS>170 && airtimeinMS<300 && doubleJumpAvailable)
    {
        player.velocity.y = JUMP_FORCE;
        doubleJumpAvailable = false;
    }
}


/*
Double jump raf
Ekta single jump er airtime 465-470 miliseconds

235+-70 er range e jump korte parbe
*/
