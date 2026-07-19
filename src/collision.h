#pragma once

#include <raylib.h>
#include "player.h"
#include "map.h"

//collision directions
const int COLLISION_NONE = 0;
const int COLLISION_TOP = 1;
const int COLLISION_BOTTOM = 2;
const int COLLISION_LEFT = 3;
const int COLLISION_RIGHT = 4;

bool isCollidiing(Player &player, Rectangle &platform)
{
    return CheckCollisionRecs(player.body, platform);
}

int GetCollisionSide(Player &player, Rectangle &platform)
{
    float playerLeft = player.body.x;
    float playerRight = player.body.x + player.body.width;
    float playerTop = player.body.y;
    float playerBottom = player.body.y + player.body.height;

    float platformLeft = platform.x;
    float platformRight = platform.x + platform.width;
    float platformTop = platform.y;
    float platformBottom = platform.y + platform.height;

    float leftOverlap = playerRight - platformLeft;
    float rightOverlap = platformRight - playerLeft;
    float topOverlap = playerBottom - platformTop;
    float bottomOverlap = platformBottom - playerTop;

    float minHorizontal = min(leftOverlap, rightOverlap);
    float minVertical = min(topOverlap, bottomOverlap);

    if (minVertical < minHorizontal)
    {
        if (topOverlap < bottomOverlap) return COLLISION_TOP;
        else return COLLISION_BOTTOM;
    }

    if (minHorizontal < minVertical)
    {
        if (leftOverlap < rightOverlap) return COLLISION_LEFT;
        else return COLLISION_RIGHT;
    }

    if (fabs(player.velocity.y) >= fabs(player.velocity.x))
    {
        if (player.velocity.y > 0) return COLLISION_TOP;
        else return COLLISION_BOTTOM;
    }
    else
    {
        if (player.velocity.x > 0) return COLLISION_LEFT;
        else return COLLISION_RIGHT;
    }
}


void ResolveCollision(Player &player, Rectangle &platform, int side)
{
    if(side == COLLISION_TOP)
    {
        player.body.y = platform.y - player.body.height;
        player.position.y = player.body.y;

        player.velocity.y = 0;

        player.grounded = true;
        player.doubleJumpAvailable = true;
    }

    else if(side == COLLISION_BOTTOM)
    {
        player.body.y = platform.y + platform.height;
        player.position.y = player.body.y;

        player.velocity.y = 0;
    }

    else if(side == COLLISION_LEFT)
    {
        player.body.x = platform.x - player.body.width;
        player.position.x = player.body.x;

        player.velocity.x = 0;
    }

    else if(side == COLLISION_RIGHT)
    {
        player.body.x = platform.x + platform.width;
        player.position.x = player.body.x;

        player.velocity.x = 0;
    }
}

void GreenCollision(Player &player,Map &map)
{
    for(int i = 0; i < map.greenCount; i++)
    {
        Rectangle &platform = map.green[i].body;

        if(isCollidiing(player, platform))
        {
            int side = GetCollisionSide(player, platform);

            ResolveCollision(player, platform, side);
        }
    }
}
void RedCollision(Player &player,Map &map)
{
    for(int i = 0; i < map.redCount; i++)
    {
        Rectangle &platform = map.red[i].body;

        if(isCollidiing(player, platform))
        {
            int side = GetCollisionSide(player, platform);

            ResolveCollision(player, platform, side);
        }
    }
}
void YellowCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.yellowCount; i++)
    {
        Rectangle &platform = map.yellow[i].body;

        if(isCollidiing(player, platform))
        {
            int side = GetCollisionSide(player, platform);

            ResolveCollision(player, platform, side);
        }
    }
}
void BlueCollision(Player &player,Map &map)
{
    for(int i = 0; i < map.blueCount; i++)
    {
        Rectangle &platform = map.blue[i].body;

        if(isCollidiing(player, platform))
        {
            int side = GetCollisionSide(player, platform);

            ResolveCollision(player, platform, side);
        }
    }
}