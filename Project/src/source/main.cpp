#include "raylib.h"


void SetWinowsRes(const int& screenWidth, const int& screenHeight)
{
    // check for alt + enter
    if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_F11))
    {
        // see what display we are on right now
        int display = GetCurrentMonitor();


        if (IsWindowFullscreen())
        {
            // if we are full screen, then go back to the windowed size
            SetWindowSize(screenWidth, screenHeight);
        }
        else
        {
            // if we are not full screen, set the window size to match the monitor we are on
            SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        }

        // toggle the state
        ToggleFullscreen();
    }
}

int main()
{
    const int screenWidth = GetScreenHeight();      // Get Screen Resolution
    const int screenHeight = GetScreenWidth();


    InitWindow(screenWidth, screenHeight, "Project B-C");       //Initializing OpenGL window


    Texture2D mainScreenTexture = LoadTexture("assets/whiteboard.png");         //load texture in VRAM
    
    SetTargetFPS(240);               //FPS locked at 240


    while (!WindowShouldClose())    //main loop
    {
        SetWinowsRes(screenWidth, screenHeight);          //function for changing window resolution

        DrawTexture(mainScreenTexture, screenWidth, screenHeight, WHITE);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        

        EndDrawing();
    }



    //clean up

    CloseWindow();

    return 0;
}