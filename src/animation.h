#pragma once

#include <stdio.h>
#include <raylib.h>
#include "player.h"


Texture2D RunRightAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "runr/runr-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D RunLeftAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "runl/runl-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D IdleRightAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "idler/idler-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D IdleLeftAnimation(Player *player)
{
    char CurrentAnimationString[30];
    snprintf(CurrentAnimationString, sizeof(CurrentAnimationString), "idlel/idlel-%d.png", player->framecount/5 + 1);
    Texture2D CurrentAnimationFrame = LoadTexture(CurrentAnimationString);
    return CurrentAnimationFrame;
}

Texture2D HookShootingAnimation(Player *player)
{
    char CurrentAnimationString[60];

    int frame = player->framecount / 5 + 1;

    if (frame > 12)
    {
        frame = 12;
    }

    snprintf(
        CurrentAnimationString,
        sizeof(CurrentAnimationString),
        "assets/hook/hook1-%d.png",
        frame
    );

    Texture2D CurrentAnimationFrame =
        LoadTexture(CurrentAnimationString);

    return CurrentAnimationFrame;
}

Texture2D HookWebAnimation(Player *player)
{
    char CurrentAnimationString[60];

    int frame = player->framecount / 5 + 1;

    if (frame > 12)
    {
        frame = 12;
    }

    snprintf(
        CurrentAnimationString,
        sizeof(CurrentAnimationString),
        "assets/hook/hook2-%d.png",
        frame
    );

    Texture2D CurrentAnimationFrame =
        LoadTexture(CurrentAnimationString);

    return CurrentAnimationFrame;
}

Texture2D HookPullingAnimation(Player *player)
{
    char CurrentAnimationString[60];

    int frame = player->framecount / 5 + 1;

    if (frame > 12)
    {
        frame = 12;
    }

    snprintf(
        CurrentAnimationString,
        sizeof(CurrentAnimationString),
        "assets/hook/hook3-%d.png",
        frame
    );

    Texture2D CurrentAnimationFrame =
        LoadTexture(CurrentAnimationString);

    return CurrentAnimationFrame;
}