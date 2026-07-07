#include <raylib.h>

struct Player
{
    Vector2 position;
    Vector2 velocity;

    Rectangle body;
    Rectangle attack;

    bool grounded;
    bool facingRight;

    int health;
};

struct Enemy
{
    Vector2 position;
    Vector2 velocity;

    Rectangle body;

    int health;
};

struct Game
{
    Player player;

    Enemy enemies[20];

    Camera2D camera;
};

int main()
{
    InitWindow(1280, 720, "Colorist");
    SetTargetFPS(60);

    Game game;

    game.player.position = {100, 300};
    game.player.velocity = {0, 0};

    game.player.body = {game.player.position.x, game.player.position.y, 32, 64};

    game.player.health = 100;
    game.player.grounded = false;
    game.player.facingRight = true;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_D))
        {
            game.player.position.x += 5;
            game.player.facingRight = true;
        }

        if (IsKeyDown(KEY_A))
        {
            game.player.position.x -= 5;
            game.player.facingRight = false;
        }

        if (IsKeyDown(KEY_W)) game.player.position.y -= 5;

        if (IsKeyDown(KEY_S)) game.player.position.y += 5;

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