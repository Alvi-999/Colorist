#pragma once

const int COLLISION_NONE = 0;
const int COLLISION_TOP = 1;
const int COLLISION_BOTTOM = 2;
const int COLLISION_LEFT = 3;
const int COLLISION_RIGHT = 4;

const int YELLOW_BREAK_TIME = 37;

// Physics constants
const float GRAVITY = 5.00f;
const float MOVE_SPEED = 3.0f;
const float JUMP_FORCE = -50.0f;

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
