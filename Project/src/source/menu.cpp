#include <iostream>
#include "../include/raylib.h"

#include "../headers/menu.hpp"
#include "../headers/settings.hpp"

#define NUM_FRAMES  1

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


    Texture2D button = LoadTexture("assets/button.png");
    float frameHeight = (float)button.height / NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };
    Rectangle btnBounds = { screenWidth / 2.0f - button.width / 2.0f, screenHeight / 2.0f - button.height / NUM_FRAMES / 2.0f, (float)button.width, frameHeight };
    int btnState = 0;
    bool btnAction = false;
    Vector2 mousePoint = { 0.0f, 0.0f };


    Texture2D mainMenuTexture = LoadTexture("assets/background.png");         //load texture in VRAM
    mainMenuTexture.width = 1600;
    mainMenuTexture.height = 900;
    Vector2 mainMenuTexturePosition = { 0, 0 };

    Texture2D logoTexture = LoadTexture("assets/Logo.png");

    Vector2 logoTexturePosition = { 0, 0 };

    Texture2D customCursor = LoadTexture("assets/cursor.png");         //load texture in VRAM
    //customCursor.width = 28;
    //customCursor.height = 28;
    Vector2 cursorPosition = { -100.0f, -100.0f };

    Texture2D soundOnIconTexture = LoadTexture("assets/speaker.png");
    Texture2D soundOffIconTexture = LoadTexture("assets/mute.png");

    Vector2 soundIconTexturePosition = { 1560.0f, 860.0f };

    SetTargetFPS(240);               //FPS locked at 240

    HideCursor();

    while (!WindowShouldClose())    //main loop
    {
        // Update
        //----------------------------------------------------------------------------------
        cursorPosition = GetMousePosition();        //cursor position

        mousePoint = GetMousePosition();
        btnAction = false;

        SetWinowsRes(screenWidth, screenHeight);          //function for changing fullscreen mode

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && isMouseInSoundIconPosition())
        {
            hoverSoundButton = !hoverSoundButton;
        }

        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {


        }

        sourceRec.y = btnState * frameHeight;

        // Draw
        BeginDrawing();

        ClearBackground(WHITE);

        DrawTextureV(mainMenuTexture, mainMenuTexturePosition, WHITE);
        DrawTextureV(logoTexture, logoTexturePosition, WHITE);

        if (!hoverSoundButton)
        {
            DrawTextureV(soundOffIconTexture, soundIconTexturePosition, WHITE);
        }
        else
        {
            DrawTextureV(soundOnIconTexture, soundIconTexturePosition, WHITE);
        }

        //DrawRectangle(660, 400, 240, 200, RED);           //FOR TESTING PURPOSES!!!

        DrawTextureRec(button, sourceRec, Vector2{ btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
        DrawText("Start", 715, screenHeight / 2.0f - button.height / NUM_FRAMES / 2.0f + 6, 60, LIGHTGRAY);

        DrawTextureV(customCursor, cursorPosition, WHITE);//draw cursor texture

        EndDrawing();
    }

    UnloadTexture(button);
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}