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
        if(CheckCollisionRecs(player.body, map.green[i].body) && player.velocity.y > 0)
        {
            player.position.y = map.green[i].body.y - player.body.height;
            player.velocity.y = 0;
            player.grounded = true;
            player.doubleJumpAvailable = true;
            player.body.y = player.position.y;
        }
    }
}

void RedCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.redCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.red[i].body) && player.velocity.y > 0)
        {
            player.position.y = map.red[i].body.y - player.body.height;
            player.velocity.y = 0;
            player.grounded = true;
            player.doubleJumpAvailable = true;
            player.body.y = player.position.y;
        }
    }
}

void YellowCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.yellowCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.yellow[i].body) && player.velocity.y > 0)
        {
            player.position.y = map.yellow[i].body.y - player.body.height;
            player.velocity.y = 0;
            player.grounded = true;
            player.doubleJumpAvailable = true;
            player.body.y = player.position.y;
        }
    }
}

void BlueCollision(Player &player, Map &map)
{
    for(int i = 0; i < map.blueCount; i++)
    {
        if(CheckCollisionRecs(player.body, map.blue[i].body) && player.velocity.y > 0)
        {
            player.position.y = map.blue[i].body.y - player.body.height;
            player.velocity.y = 0;
            player.grounded = true;
            player.doubleJumpAvailable = true;
            player.body.y = player.position.y;
        }
    }
}