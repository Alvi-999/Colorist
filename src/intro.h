#include "raymedia.h"

void PlayIntro()
{
    MediaStream Painters_Intro = LoadMedia("main_menu/painters.mp4");

    float start_time = GetTime();

    while (!WindowShouldClose())
    {
        UpdateMedia(&Painters_Intro);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(Painters_Intro.videoTexture, 0, 0, WHITE);
        EndDrawing();

        float current_time = GetTime() - start_time;
        if(current_time>=3.5)
        {
            break;
        }
    }

    UnloadMedia(&Painters_Intro);
}