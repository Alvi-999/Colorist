#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;

Rectangle ground = {0, 650, 1280, 70};

//the necessary infos about the player
struct Player
{
    //player er current position
    Vector2 position;

    //velocity of player

    
    Vector2 velocity;

    //graphics
    Texture2D sprite;

    //the hitbox 
    Rectangle body;

    //attack korle je range e oy attack korbe
    Rectangle attack;

    //player kono platform e ase ki na
    bool grounded;

    //kondike firra ase oita bujte
    bool facingRight;

    int health;
};

//the things necessary to design the enemy
//dont need to use it before the project presentation
struct Enemy
{
    Vector2 position;
    Vector2 velocity;

    Rectangle body;

    int health;
};


//gives you the full control of all the controllables and enemies in the game
struct Game
{
    Player player;

    Enemy enemies[20];

    //camera controls
    Camera2D camera;
};

//handles necessary inputs
void InputHandling(Game &game)
{
    game.player.velocity.x = 0;

    if(IsKeyDown(KEY_RIGHT))
    {
        game.player.velocity.x += 5;
        game.player.facingRight = true;
    }
    if(IsKeyDown(KEY_LEFT))
    {
        game.player.velocity.x -= 5;
        game.player.facingRight = false;
    }
}

//updates the necessary things in each iteration
void Update(Game &game)
{
    //added gravity
    game.player.velocity.y += 1;

    //speed onujayi jabe
    game.player.position.x += game.player.velocity.x;
    game.player.position.y += game.player.velocity.y;
    
    //player er position er shathe hitbox move korabo
    game.player.body.x = game.player.position.x;
    game.player.body.y = game.player.position.y;

    if(CheckCollisionRecs(game.player.body, ground))
    {
        game.player.position.y = ground.y - game.player.body.height;

        game.player.velocity.y = 0;

        game.player.grounded = true;
    }
    else 
    {
        game.player.grounded = false;
    }
}

//draws the frames in each iteration
void DrawCanvas(Game &game)
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawRectangleRec(ground, DARKGRAY);
    
    DrawRectangleRec(game.player.body, BLUE);

    EndDrawing();
}

int main()
{
    InitWindow(1280, 720, "Colorist");
    SetTargetFPS(60);

    //our main workzone
    Game game;

    game.player.position = {100, 300};
    game.player.velocity = {0, 0};

    game.player.body = {game.player.position.x, game.player.position.y, 32, 64};

    game.player.health = 100;
    game.player.grounded = false;
    game.player.facingRight = true;

    while (!WindowShouldClose())
    {
        //shob input eikhane jabe
        InputHandling(game);

        //updates the necessary parameters
        Update(game);

        //draws the canvas
        DrawCanvas(game);
    }

    CloseWindow();

    return 0;
}