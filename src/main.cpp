#include <bits/stdc++.h>
#include <raylib.h>

const int IDLE = 0;
const int RUN = 1;
const int JUMP = 2;
const int FALL = 3;
const int ATTACK = 4;
const int DASH = 5;


using namespace std;

Rectangle ground = {0, 650, 1280, 70};


struct Platform
{
    Rectangle body;
};

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

    //player kon state e ase oita
    int state;

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

    Platform platforms[20];

    int platform_count;

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

    if(IsKeyPressed(KEY_UP) && game.player.grounded)
    {
        game.player.velocity.y = -18;
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

    for(int i = 0; i < game.platform_count; i++)
    {
        game.player.grounded = false;

        if(CheckCollisionRecs(game.player.body, game.platforms[i].body))
        {
            game.player.position.y = ground.y - game.player.body.height;

            game.player.velocity.y = 0;

            game.player.grounded = true;

            //updating hitbox according to the position of the player
            game.player.body.y = game.player.position.y;

            break;
        }
    }
}

//draws the frames in each iteration
void DrawCanvas(Game &game)
{
    BeginDrawing();

    ClearBackground(BLACK);

    for(int i = 0; i < game.platform_count; i++)
    {
        DrawRectangleRec(game.platforms[i].body, DARKGRAY);
    }
    
    DrawRectangleRec(game.player.body, BLUE);

    EndDrawing();
}

int main()
{
    InitWindow(1280, 720, "Colorist");
    SetTargetFPS(60);

    //our main workzone
    Game game;

    game.platform_count = 3;

    game.platforms[0].body = {0, 650, 1280, 70};
    game.platforms[1].body = {250, 650, 1280, 70};
    game.platforms[2].body = {650, 400, 250, 20};

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