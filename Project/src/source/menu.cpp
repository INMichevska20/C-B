#include <iostream>
#include "raylib.h"

#include "../headers/menu.hpp"
#include "../headers/settings.hpp"

#define RAYGUI_IMPLEMENTATION

void menu()
{
    const float screenWidth = 1600;       //fixed window resolution
    const float screenHeight = 900;

    bool encyclopedia = true;
    bool quiz = true;
    bool skeleton = true;
    bool exit = true;


    InitWindow(screenWidth, screenHeight, "Project B-C");       //Initializing OpenGL window



    Texture2D mainMenuTexture = LoadTexture("assets/background.png");         //load texture in VRAM
    mainMenuTexture.width = 1600;
    mainMenuTexture.height = 900;
    Vector2 mainMenuTexturePosition = { 0, 0 };

    Texture2D logoTexture = LoadTexture("assets/Logo.png");

    Vector2 logoTexturePosition = { 534, 100 };

    Texture2D customCursor = LoadTexture("assets/customCursor.png");         //load texture in VRAM
    customCursor.width = 93;
    customCursor.height = 175;

    Vector2 cursorPosition = { -100.0f, -100.0f };


    SetTargetFPS(240);               //FPS locked at 240

    HideCursor();

    while (!WindowShouldClose())    //main loop
    {
        // Update
        //----------------------------------------------------------------------------------
        cursorPosition = GetMousePosition();        //cursor position
        cursorPosition.x -= 31.5f;

        SetWinowsRes(screenWidth, screenHeight);          //function for changing fullscreen mode



        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);
        DrawTextureV(mainMenuTexture, mainMenuTexturePosition, WHITE);
        DrawTextureV(logoTexture, logoTexturePosition, WHITE);

        //DrawRectangle(660, 400, 240, 200, RED);           //FOR TESTING PURPOSES!!!

        DrawTextureV(customCursor, cursorPosition, WHITE);      //draw cursor texture


        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}