#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;

int main()
{
    InitWindow(800, 500, "Colorist");

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("HELLO COLORIST!", 220, 200, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}