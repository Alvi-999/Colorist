#include "raymedia.h"

void DelayDisplayImage(Texture2D texture, Camera2D camera, float delaytime)
{
    float start_time = GetTime();
    
    while( GetTime() - start_time < delaytime )
    {
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera);
                DrawTexture(texture, 0, 0, WHITE);
            EndMode2D();
        EndDrawing();
    }
}

void PlayIntro()
{
    MediaStream Painters_Intro = LoadMedia("main_menu/painters.mp4");
    Texture2D intro_born = LoadTexture("start/1.born.png");
    Texture2D intro_think = LoadTexture("start/2.think.png");
    MediaStream intro_why = LoadMedia("start/3.why.mp4");
    Texture2D intro_lookup = LoadTexture("start/4.lookUp.png");
    MediaStream intro_hasitall = LoadMedia("start/6.hasitall.mp4");
    MediaStream intro_get = LoadMedia("start/7.get.mp4");
    MediaStream intro_become = LoadMedia("start/8.become.mp4");
    MediaStream intro_colorist = LoadMedia("start/9.colorist.mp4");

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

    //----------------------1.Intro-----------------------------------
    Camera2D camera_intro;
    camera_intro.target = (Vector2) { 0.0f, 0.0f };
    camera_intro.offset = (Vector2) { 0.0f, 0.0f };
    camera_intro.rotation = 0.0f;
    camera_intro.zoom = 1.0f;

    DelayDisplayImage(intro_born, camera_intro, 2);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera_intro);
                DrawTexture(intro_born, 0, 0, WHITE);
            EndMode2D();
        EndDrawing();

        camera_intro.target.x+=2;

        if ( camera_intro.target.x + 1920 >= 2304 )
        {
            break;
        }
    }

    DelayDisplayImage(intro_born, camera_intro, 2);
    
    //----------------------2.think-------------------------------
    camera_intro.target = (Vector2) { 0.0f, 0.0f };
    camera_intro.offset = (Vector2) { 0.0f, 0.0f };
    camera_intro.rotation = 0.0f;
    camera_intro.zoom = 1.0f;

    DelayDisplayImage(intro_think, camera_intro, 1.5);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera_intro);
                DrawTexture(intro_think, 0, 0, WHITE);
            EndMode2D();
        EndDrawing();

        camera_intro.target.x+=2;

        if ( camera_intro.target.x + 1920 >= 2304 )
        {
            break;
        }
    }

    DelayDisplayImage(intro_think, camera_intro, 2);

    //---------------------------3.Why--------------------------------
    start_time = GetTime();

    while (!WindowShouldClose())
    {
        UpdateMedia(&intro_why);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(intro_why.videoTexture, 0, 0, WHITE);
        EndDrawing();

        float current_time = GetTime() - start_time;
        if(current_time >= 9)
        {
            break;
        }
    }

    //----------------------------4.Lookup-------------------------------
    camera_intro.target = (Vector2) { 0.0f, 840.0f };
    camera_intro.offset = (Vector2) { 0.0f, 0.0f };
    camera_intro.rotation = 0.0f;
    camera_intro.zoom = 1.0f;

    DelayDisplayImage(intro_lookup, camera_intro, 2);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera_intro);
                DrawTexture(intro_lookup, 0, 0, WHITE);
            EndMode2D();
        EndDrawing();

        camera_intro.target.y-=2;

        if ( camera_intro.target.y <= 0 )
        {
            break;
        }
    }

    DelayDisplayImage(intro_lookup, camera_intro, 2);  
    
    //------------------------6.hasitall---------------------------------
    start_time = GetTime();

    while (!WindowShouldClose())
    {
        UpdateMedia(&intro_hasitall);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(intro_hasitall.videoTexture, 0, 0, WHITE);
        EndDrawing();

        float current_time = GetTime() - start_time;
        if(current_time >= 6)
        {
            break;
        }
    }

    //-------------------------7.get-------------------------------------
    start_time = GetTime();

    while (!WindowShouldClose())
    {
        UpdateMedia(&intro_get);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(intro_get.videoTexture, 0, 0, WHITE);
        EndDrawing();

        float current_time = GetTime() - start_time;
        if(current_time >= 3)
        {
            break;
        }
    }

    //---------------------------8.become--------------------------------
    camera_intro.target = (Vector2) { GetScreenWidth()/2.0f , GetScreenHeight()/2.0f };
    camera_intro.offset = (Vector2) { GetScreenWidth()/2.0f , GetScreenHeight()/2.0f };
    camera_intro.rotation = 0.0f;
    camera_intro.zoom = 1.0f;
    start_time = GetTime();

    while (!WindowShouldClose())
    {
        UpdateMedia(&intro_become);

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera_intro);
                DrawTexture(intro_become.videoTexture, 0, 0, WHITE);
            EndMode2D();
        EndDrawing();

        camera_intro.target.x+=1;

        if(camera_intro.target.x - (1920/2) >= 240)
        {
            break;
        }
    }

    //---------------------9.colorist-----------------------
    start_time = GetTime();

    while (!WindowShouldClose())
    {
        UpdateMedia(&intro_colorist);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(intro_colorist.videoTexture, 0, 0, WHITE);
        EndDrawing();

        float current_time = GetTime() - start_time;
        if(current_time >= 9)
        {
            break;
        }
    }


    UnloadMedia(&Painters_Intro);
    UnloadTexture(intro_born);
    UnloadTexture(intro_think);
    UnloadMedia(&intro_why);
    UnloadTexture(intro_lookup);
    UnloadMedia(&intro_hasitall);
    UnloadMedia(&intro_get);
    UnloadMedia(&intro_become);
    UnloadMedia(&intro_colorist);
}

