#include "raylib.h"

int main()
{
    const int screenWidth = 1920;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(SKYBLUE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}