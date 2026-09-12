#pragma once

#include "player.h"

void StartAttack(Player *player)
{
    if(player->state == DEFEND ||
       player->state == ATTACK ||
       player->state == DEATH)
    {
        return;
    }

    player->state = ATTACK;
    player->attackTimer = 0;

    if(player->facingRight)
    {
        player->attack = (Rectangle)
        {
            player->body.x + player->body.width,
            player->body.y + 15,
            40,
            30
        };
    }
    else
    {
        player->attack = (Rectangle)
        {
            player->body.x - 40,
            player->body.y + 15,
            40,
            30
        };
    }
}

void UpdateAttack(Player *player)
{
    if(player->state != ATTACK)
    {
        return;
    }

    player->attackTimer++;

    //attack hitbox is active
    if(player->attackTimer >= ATTACK_STARTUP && player->attackTimer < ATTACK_STARTUP + ATTACK_ACTIVE)
    {
        if(player->facingRight)
        {
            player->attack.x = player->body.x + player->body.width;
        }
        else 
        {
            player->attack.x = player->body.x - player->attack.width;
        }

        player->attack.y = player->body.y + 15;
    }

    //attack finished
    if(player->attackTimer >= (ATTACK_STARTUP + ATTACK_ACTIVE + ATTACK_RECOVERY))
    {
        player->attackTimer = 0;

        if(player->facingRight) player->state = IDLER;
        else player->state = IDLEL;
    }
}

void StartDefence(Player *player)
{
    if(player->state == ATTACK)
    {
        return;
    }

    player->state = DEFEND;
    player->defending = true;
}
void UpdateDefence(Player *player)
{
    if(!IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        player->defending = false;

        if(player->state == DEFEND) 
        {
            if(player->facingRight) player->state = IDLER;
            else player->state = IDLEL;
        }
    }
}

void TakeDamage(Player *player, int damage)
{
    if(player->defending)
    {
        return;
    }

    player->hits -= damage;

    if(player->hits < 0)
    {
        player->hits = 0;
        player->state = DEATH;

        RespawnPlayer(player);
    }
}