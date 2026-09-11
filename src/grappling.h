#pragma once

#include <raylib.h>
#include <stdbool.h>
#include "constants.h"

typedef struct GrapplingHook
{
    Vector2 position;
    Vector2 direction;
    Vector2 attachPoint;

    float distanceTravelled;    
    bool attached;
    
    int state;
} GrapplingHook;

