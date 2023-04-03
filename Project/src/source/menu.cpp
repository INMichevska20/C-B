#include <iostream>
#include "../include/raylib.h"

#include "../headers/menu.hpp"
#include "../headers/settings.hpp"

#define NUM_FRAMES  1

bool isMouseInSoundIconPosition()
{
    return (GetMouseX() >= 1500 && GetMouseY() >= 800);
}

void menu()
{
    const float screenWidth = 1600;       //fixed window resolution
    const float screenHeight = 900;

    bool hoverSoundButton = false;
    bool isInMenu = true;
    bool encyclopedia = false;
    bool quiz = false;
    bool skeleton = false;
    bool exit = false;
    bool isExitButtonPressed = false;


    InitWindow(screenWidth, screenHeight, "Project B-C");       //Initializing OpenGL window


    Texture2D button = LoadTexture("assets/button.png");
    float frameHeight = (float)button.height / NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };

    Color underButtonRectangleColor = { 92, 87, 79, 200 };
    Rectangle underButtonRectangle[4] = {
        {655.0f, 350.0f, 310.0f, 75.0f},
        {655.0f, 450.0f, 310.0f, 75.0f},
        {655.0f, 550.0f, 310.0f, 75.0f},
        {655.0f, 650.0f, 310.0f, 75.0f}
    };

    Rectangle btnBounds = {
        screenWidth / 2.0f - button.width / 2.0f,
        screenHeight / 2.0f - button.height / NUM_FRAMES / 2.0f,
        (float)button.width,
        frameHeight
    };

    int btnState = 0;
    bool btnAction = false;


    Texture2D backgroundTexture = LoadTexture("assets/background.png");         //load texture in VRAM
    Texture2D logoTexture = LoadTexture("assets/Logo.png");


    Texture2D buttonEncyclopediaTexture = LoadTexture("assets/Menu/Buttons/EncyclopediaButton.png");           //Buttons' Texture
    Texture2D buttonQuizTexture = LoadTexture("assets/Menu/Buttons/QuizButton.png");
    Texture2D buttonskeletonTexture = LoadTexture("assets/Menu/Buttons/SkeletonButton.png");
    Texture2D buttonExitTexture = LoadTexture("assets/Menu/Buttons/ExitButton.png");

    Texture2D buttonТextures[4] = {
        buttonEncyclopediaTexture,
        buttonQuizTexture,
        buttonskeletonTexture,
        buttonExitTexture,
    };

    Texture2D soundOnIconTexture = LoadTexture("assets/speaker.png");
    Texture2D soundOffIconTexture = LoadTexture("assets/mute.png");

    Vector2 mainMenuTexturePosition = { 0, 0 };
    Vector2 logoTexturePosition = { 609, 32 };
    Vector2 buttonPosition[4] = {
        {648.0f, 343.0f},
        {648.0f, 443.0f},
        {648.0f, 543.0f},
        {648.0f, 643.0f}
    };



    Texture2D customCursor = LoadTexture("assets/cursor.png");         //load texture in VRAM
    Vector2 cursorPosition;
    Vector2 soundIconTexturePosition = { 1500.0f, 800.0f };



    SetTargetFPS(240);               //FPS locked at 240

    HideCursor();

    while (!WindowShouldClose())    //main loop
    {
        // Update
        //----------------------------------------------------------------------------------
        cursorPosition = GetMousePosition();        //cursor position
        cursorPosition.x -= 3;

        btnAction = false;

        SetWinowsRes(screenWidth, screenHeight);          //function for changing fullscreen mode

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[0]))
        {
            encyclopedia = !encyclopedia;
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[1]))
        {
            quiz = !quiz;
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[2]))
        {
            skeleton = !skeleton;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && isMouseInSoundIconPosition())
        {
            hoverSoundButton = !hoverSoundButton;
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[3]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            isExitButtonPressed = !isExitButtonPressed;
        }

        if (CheckCollisionPointRec(cursorPosition, btnBounds))
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

        if (isInMenu)
        {
            DrawTextureV(backgroundTexture, mainMenuTexturePosition, RAYWHITE);
            DrawTextureV(logoTexture, logoTexturePosition, RAYWHITE);

            for (int i = 0; i < 4; i++)
            {
                DrawRectangleRounded(underButtonRectangle[i], 0.45, 1, underButtonRectangleColor);
                if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[i]))
                {
                    DrawTexture(buttonТextures[i], buttonPosition[i].x + 7, buttonPosition[i].y + 7, RAYWHITE);
                }
                else
                {
                    DrawTextureV(buttonТextures[i], buttonPosition[i], RAYWHITE);
                }
            }
        }



        if (!hoverSoundButton)
        {
            DrawTextureV(soundOffIconTexture, soundIconTexturePosition, WHITE);
        }
        else
        {
            DrawTextureV(soundOnIconTexture, soundIconTexturePosition, WHITE);
        }

        DrawTextureV(customCursor, cursorPosition, WHITE); //draw cursor texture
        EndDrawing();

        if (isExitButtonPressed)
        {
            break;
        }
    }

    UnloadTexture(button);
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}