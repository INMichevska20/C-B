#include <iostream>
#include "raylib.h"

#include "../headers/menu.hpp"
#include "../headers/settings.hpp"


bool isMouseInSoundIconPosition()
{
    return(GetMouseX() >= 1560 && GetMouseY() >= 860);
}

void menu()
{
    const float screenWidth = 1600;       //fixed window resolution
    const float screenHeight = 900;

    bool hoverSoundButton = false;
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

    Texture2D customCursor = LoadTexture("assets/cursor.png");         //load texture in VRAM
    //customCursor.width = 28;
    //customCursor.height = 28;
    Vector2 cursorPosition = { -100.0f, -100.0f };

    Texture2D soundOnIconTexture = LoadTexture("assets/speaker.png");
    Texture2D soundOffIconTexture = LoadTexture("assets/mute.png");
    Texture2D emptySoundIconTexture = soundOffIconTexture;

    Vector2 soundIconTexturePosition = { 1560.0f, 860.0f };

    SetTargetFPS(240);               //FPS locked at 240

    HideCursor();

    while (!WindowShouldClose())    //main loop
    {
        // Update
        //----------------------------------------------------------------------------------
        cursorPosition = GetMousePosition();        //cursor position

        SetWinowsRes(screenWidth, screenHeight);          //function for changing fullscreen mode

        if (isMouseInSoundIconPosition())
        {
            emptySoundIconTexture = soundOnIconTexture;
            hoverSoundButton = true;
        }
        else
        {
            hoverSoundButton = false;
        }
        

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);
        DrawTextureV(mainMenuTexture, mainMenuTexturePosition, WHITE);
        DrawTextureV(logoTexture, logoTexturePosition, WHITE);

        if (!hoverSoundButton)
        {
            //released = true;
            DrawTextureV(soundOffIconTexture, soundIconTexturePosition, WHITE);
        }
        else
        {
            //released = false;
            DrawTextureV(soundOnIconTexture, soundIconTexturePosition, WHITE);
        }

        //DrawRectangle(660, 400, 240, 200, RED);           //FOR TESTING PURPOSES!!!

        DrawTextureV(customCursor, cursorPosition, WHITE);      //draw cursor texture


        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}