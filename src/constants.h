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
#define IDLEL 0
#define IDLER 1
#define RUNL 2
#define RUNR 3
#define JUMPL 4
#define JUMPR 5
#define FALL 6
#define ATTACK 7
#define DASH 8
#define DEFEND 9
#define DEATH 10

#define ATTACK_STARTUP 5
#define ATTACK_ACTIVE 10
#define ATTACK_RECOVERY 15

#define HOOK_IDLE 16; 
#define HOOK_SHOOTING 17;
#define HOOK_PULLING 18;
#define HOOK RETRACTING 19;

const float HOOK_SPEED = 15.0f;
const float HOOK_PULL_SPEED = 10.0f;
const float HOOK_MAX_DISTANCE = 450.0f;

#define ATTACK_DAMAGE 1

const int MAX_HITS = 5;