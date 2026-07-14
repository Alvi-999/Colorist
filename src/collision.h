#pragma once 

#include <raylib.h>
#include "map.h"
#include "game.h"

void LandPlayer(Player &player, Rectangle platform)
{
    player.position.y = platform.y - player.body.height;

    player.velocity.y = 0;

    player.grounded = true;

    player.doubleJumpAvailable = true;

    player.body.y = player.position.y;
}

void GreenCollision(Player &player, Map &map)
{
    player.grounded = false;

    for(int i = 0; i < map.greenCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.green[i].body))
        {
            LandPlayer(player, map.green[i].body);
            break;
        }
    }
}

void RedCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.redCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.red[i].body))
        {
            LandPlayer(player, map.red[i].body);
            break;
        }
    }
}

void YellowCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.redCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.yellow[i].body))
        {
            LandPlayer(player, map.yellow[i].body);
            break;
        }
    }
}

void BlueCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.blueCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.blue[i].body))
        {
            player.velocity.y -= map.blue[i].buoyancy;
        }
    }
}