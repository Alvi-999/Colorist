#pragma once

constexpr int COLLISION_NONE = 0;
constexpr int COLLISION_TOP = 1;
constexpr int COLLISION_BOTTOM = 2;
constexpr int COLLISION_LEFT = 3;
constexpr int COLLISION_RIGHT = 4;

constexpr int YELLOW_BREAK_TIME = 37;

// Physics constants
constexpr float GRAVITY = 5.00f;
constexpr float MOVE_SPEED = 5.0f;
constexpr float JUMP_FORCE = -25.0f;

// Player states
constexpr int IDLEL = 0;
constexpr int IDLER = 1;
constexpr int RUNL = 2;
constexpr int RUNR = 3;
constexpr int JUMPL = 4;
constexpr int JUMPR = 5;
constexpr int FALL = 6;
constexpr int ATTACK = 7;
constexpr int DASH = 8;

constexpr int MAX_HITS = 5;
