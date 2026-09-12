#include "raylib.h"
#include "constants.h"

int Menu_State;
int Menu_Framecount = 0;

Texture2D blank_menu;

Texture2D play_game, play_game_inv;
Texture2D continue_game, continue_game_inv;
Texture2D rules, rules_inv;
Texture2D quit, quit_inv;

Texture2D menu_sprite[12];

bool play_game_inverted = false;
bool continue_game_inverted = false;
bool rules_inverted = false;
bool quit_inverted = false;

void UnloadAllMenuTexture()
{
    UnloadTexture(blank_menu);
    UnloadTexture(play_game);
    UnloadTexture(play_game_inv);
    UnloadTexture(continue_game);
    UnloadTexture(continue_game_inv);
    UnloadTexture(rules);
    UnloadTexture(rules_inv);
    UnloadTexture(quit);
    UnloadTexture(quit_inv);
}

void InitializeMenu()
{
    Menu_State = MENU_MAIN;

    blank_menu = LoadTexture("main_menu/blank_menu.png");

    play_game     = LoadTexture("main_menu/play_game.png");
    play_game_inv = LoadTexture("main_menu/play_game_inv.png");

    continue_game     = LoadTexture("main_menu/continue.png");
    continue_game_inv = LoadTexture("main_menu/continue_inv.png");

    rules     = LoadTexture("main_menu/rules.png");
    rules_inv = LoadTexture("main_menu/rules_inv.png");

    quit     = LoadTexture("main_menu/quit.png");
    quit_inv = LoadTexture("main_menu/quit_inv.png");

    for (int i=0; i<12; i++)
    {
        char animation_frame[30];
        snprintf(animation_frame, sizeof(animation_frame), "main_menu/animatics-%d.png", i+1);
        menu_sprite[i] = LoadTexture(animation_frame);
    }
}

void UpdateMenu()
{
    Menu_Framecount=(Menu_Framecount+1)%60;

    play_game_inverted = false;
    continue_game_inverted = false;
    rules_inverted = false;
    quit_inverted = false;

    Vector2 MousePosition = GetMousePosition();

    if ( MousePosition.x > 1270 && MousePosition.x < 1270+600 && MousePosition.y > 50 && MousePosition.y < 50+160 ) //play game
    {
        play_game_inverted = true;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Menu_State = MENU_GAME;
        }
    }
    else if ( MousePosition.x > 1330 && MousePosition.x < 1330+500 && MousePosition.y > 210 && MousePosition.y < 210+160 ) //continue game
    {
        continue_game_inverted = true;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Menu_State = MENU_GAME;
        }
    }
    else if (MousePosition.x > 1450 && MousePosition.x < 1450+400 && MousePosition.y > 320 && MousePosition.y < 320+160) //rules
    {
        rules_inverted = true;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Menu_State = MENU_RULEBOOK;
        }
    }
    else if( MousePosition.x > 1550 && MousePosition.x < 1550+300 && MousePosition.y > 465 && MousePosition.y < 465+160 ) //quit
    {
        quit_inverted = true;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Menu_State = MENU_QUIT;
        }
    }
}

void DrawMenu()
{
    DrawTexture(blank_menu, 0, 0, WHITE);

    DrawTexturePro(
        play_game_inverted ? play_game_inv : play_game,
        (Rectangle) { 0.0f, 0.0f, (float)play_game.width, (float)play_game.height },
        (Rectangle) { 1270.0f, 50.0f, 600.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f }, 0.0f, WHITE
    );

    DrawTexturePro(
        continue_game_inverted ? continue_game_inv : continue_game,
        (Rectangle) { 0.0f, 0.0f, (float)continue_game.width, (float)continue_game.height },
        (Rectangle) { 1330.0f, 210.0f, 500.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f }, 0.0f, WHITE
    );

    DrawTexturePro(
        rules_inverted ? rules_inv : rules,
        (Rectangle) { 0.0f, 0.0f, (float)rules.width, (float)rules.height },
        (Rectangle) { 1450.0f, 320.0f, 400.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f }, 0.0f, WHITE
    );

    DrawTexturePro(
        quit_inverted ? quit_inv : quit,
        (Rectangle) { 0.0f, 0.0f, (float)quit.width, (float)quit.height },
        (Rectangle) { 1550.0f, 465.0f, 300.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f }, 0.0f, WHITE
    );

    DrawTexturePro(
        menu_sprite[(Menu_Framecount/5)],
        (Rectangle) { 0.0f, 0.0f, (float)menu_sprite[Menu_Framecount%12].width, (float)menu_sprite[Menu_Framecount%12].height },
        (Rectangle) { 0.0f, 0.0f, 1920.0f, 1080.0f},
        (Vector2) { 0.0f, 0.0f }, 0.0f, WHITE
    );
}