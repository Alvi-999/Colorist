#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;

//the necessary infos about the player
struct Player
{
    //player er current position
    Vector2 position;

    //Nicher dike porar speed
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
void Inputs(Game &game)
{
    if(IsKeyDown(KEY_D))
    {
        game.player.position.x += 5;
        game.player.facingRight = true;
    }
    if(IsKeyDown(KEY_A))
    {
        game.player.position.x -= 5;
        game.player.facingRight = false;
    }
    if(IsKeyDown(KEY_S)) game.player.position.y += 5;
    
    if(IsKeyDown(KEY_W)) game.player.position.y -= 5;
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
        Inputs(game);


        game.player.body.x = game.player.position.x;
        game.player.body.y = game.player.position.y;

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangleRec(game.player.body, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}