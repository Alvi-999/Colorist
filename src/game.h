#pragma once

#include <raylib.h>

#include "player.h"
#include "map.h"
#include "collision.h"
#include "combat.h"
#include "constants.h"

void UpdateGame(Player *player, Map *map)
{
    InputHandling(player, map);
    
    UpdateAttack(player);
    UpdateDefence(player);

    UpdateMovement(player);
    UpdatePlayerState(player);

    GreenCollision(player, map);
    RedCollision(player, map);
    YellowCollision(player, map);
    BlueCollision(player, map);

    UpdateYellowPlatforms(map);
}

void DrawGame(Player *player, Map *map)
{
    DrawMap(map);

    DrawPlayer(player);
}