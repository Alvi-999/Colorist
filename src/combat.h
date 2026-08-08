#pragma once

#include "player.h"

void StartAttack(Player *player)
{
    if(player->state == ATTACK || player->defending)
    {
        return;
    }

    player->state = ATTACK;
    player->attackTimer = 0;

    //put the attack hitbox in front of the player
    if(player->facingRight)
    {
        player->attack = (Rectangle)
        {
            player->body.x + player->body.width,
            player->body.y + 15, 
            40, 30
        };
    }
    else 
    {
        player->attack = (Rectangle)
        {
            player->body.x - 40, 
            player->body.y + 15, 
            40, 30
        };
    }
}
void UpdateAttack(Player *player);

void StartDefence(Player *player);
void UpdateDefence(Player *player);

void TakeDamage(Player *player, int damage);