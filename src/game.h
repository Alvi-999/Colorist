#pragma once

#include <raylib.h>
#include "player.h"
#include "map.h"
#include "collision.h"

void UpdateGame(Player &player, Map &map)
{
    //read keyboard & mouse
    InputHandling(player);

    UpdateMovement(player);

    //collision
    GreenCollision(player, map);
    RedCollision(player, map);
    YellowCollision(player, map);
    BlueCollision(player, map);

    //animation state
    UpdatePlayerState(player);
}

void DrawGame(Player &player, Map &map)
{
    DrawMap(map);

    DrawPlayer(player);
}