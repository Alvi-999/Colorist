#include "raylib.h"
#include "constants.h"

int Menu_State;

Texture2D blank_menu;
Texture2D play_game;
Texture2D continue_game;
Texture2D rules;
Texture2D quit;

bool play_game_inverted = false;
bool continue_game_inverted = false;
bool rules_inverted = false;
bool quit_inverted = false;

void InitializeMenu()
{
    Menu_State = MENU_MAIN;

    blank_menu = LoadTexture("main_menu/blank_menu.png");

    play_game = LoadTexture("main_menu/play_game.png");
    continue_game = LoadTexture("main_menu/continue.png");
    rules = LoadTexture("main_menu/rules.png");
    quit = LoadTexture("main_menu/quit.png");
}

void UpdateMenu()
{
    play_game_inverted = false;
    continue_game_inverted = false;
    rules_inverted = false;
    quit_inverted = false;

    play_game = LoadTexture("main_menu/play_game.png");
    continue_game = LoadTexture("main_menu/continue.png");
    rules = LoadTexture("main_menu/rules.png");
    quit = LoadTexture("main_menu/quit.png");

    Vector2 MousePosition = GetMousePosition();

    if ( MousePosition.x > 1270 && MousePosition.x < 1270+600 && MousePosition.y > 50 && MousePosition.y < 50+160 ) //play game
    {
        play_game_inverted = true;
    }
    else if ( MousePosition.x > 1330 && MousePosition.x < 1330+500 && MousePosition.y > 180 && MousePosition.y < 180+160 ) //continue game 
    {
        continue_game_inverted = true;
    }
    else if (MousePosition.x > 1450 && MousePosition.x < 1450+400 && MousePosition.y > 320 && MousePosition.y < 320+160) //rules
    {
        rules_inverted = true;
    } 
    else if( MousePosition.x > 1550 && MousePosition.x < 1550+300 && MousePosition.y > 465 && MousePosition.y < 465+160 ) //quit
    {
        quit_inverted = true;
    }

    if (play_game_inverted)
    {
        play_game = LoadTexture("main_menu/play_game_inv.png");
    }
    else if(continue_game_inverted)
    {
        continue_game = LoadTexture("main_menu/continue_inv.png");
    }
    else if(rules_inverted)
    {
        rules = LoadTexture("main_menu/rules_inv.png");
    }
    else if(quit_inverted)
    {
        quit = LoadTexture("main_menu/quit_inv.png");
    }
}

void DrawMenu()
{
    DrawTexture(blank_menu, 0, 0, WHITE);

    // Play Game
    DrawTexturePro(
        play_game,
        (Rectangle) { 0.0f, 0.0f, (float)play_game.width, (float)play_game.height },
        (Rectangle) { 1270.0f, 50.0f, 600.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f },
        0.0f,
        WHITE
    );

    // Continue
    DrawTexturePro(
        continue_game,
        (Rectangle) { 0.0f, 0.0f, (float)continue_game.width, (float)continue_game.height },
        (Rectangle) { 1330.0f, 180.0f, 500.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f },
        0.0f,
        WHITE
    );

    // Rules
    DrawTexturePro(
        rules,
        (Rectangle) { 0.0f, 0.0f, (float)rules.width, (float)rules.height },
        (Rectangle) { 1450.0f, 320.0f, 400.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f },
        0.0f,
        WHITE
    );

    // // Quit
    
    DrawTexturePro(
        quit,
        (Rectangle) { 0.0f, 0.0f, (float)quit.width, (float)quit.height },
        (Rectangle) { 1550.0f, 465.0f, 300.0f, 160.0f },
        (Vector2) { 0.0f, 0.0f },
        0.0f,
        WHITE
    );
}



