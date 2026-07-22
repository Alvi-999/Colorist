#pragma once

#include <raylib.h>
#include "player.h"
#include "map.h"
#include "collision.h"

void UpdateGame(Player &player, Map &map)
{
    InputHandling(player);
    UpdateMovement(player);

    GreenCollision(player, map);
    RedCollision(player, map);
    YellowCollision(player, map);
    BlueCollision(player, map);

    UpdateYellowPlatforms(map);   // <-- here

    DrawMap(map);
    DrawPlayer(player);
}

void DrawGame(Player &player, Map &map)
{
    DrawMap(map);

    DrawPlayer(player);
}