#pragma once
#include <raylib.h>

#include "player.h"
#include "map.h"
#include "collision.h"
#include "combat.h"
#include "constants.h"
#include "boss.h"

void UpdateGame(Player *player, Map *map, Boss *boss)
{
    InputHandling(player, map, boss);
    
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

void DrawGame(Player *player, Map *map, Boss *boss)
{
    DrawMap(map);

    DrawPlayer(player);
    DrawBoss(boss);
}