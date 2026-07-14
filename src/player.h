#pragma once

#include <raylib.h>
#include <bits/stdc++.h>


// Physics constants
const float GRAVITY = 0.8f;
const float MOVE_SPEED = 5.0f;
const float JUMP_FORCE = -18.0f;

// Player states
const int IDLE = 0;
const int RUN = 1;
const int JUMP = 2;
const int FALL = 3;
const int ATTACK = 4;
const int DASH = 5;

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

