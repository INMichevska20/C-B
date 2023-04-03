﻿#include <iostream>
#include "../include/raylib.h"

#include "../headers/menu.hpp"
#include "../headers/settings.hpp"

bool isMouseInSoundIconPosition()
{
    return (GetMouseX() >= 1500 && GetMouseY() >= 800);
}

void menu()
{
    const float screenWidth = 1600;       //fixed window resolution
    const float screenHeight = 900;

    int i = 0;

    bool hoverSoundButton = false;
    bool isInMenu = true;
    bool encyclopedia = false;
    bool quiz = false;
    bool skeleton = false;
    bool exit = false;
    bool isExitButtonPressed = false;


    InitWindow(screenWidth, screenHeight, "Project B-C");       //Initializing OpenGL window


    Color underButtonRectangleColor = { 92, 87, 79, 200 };
    Rectangle underButtonRectangle[4] = {
        {655.0f, 350.0f, 310.0f, 75.0f},
        {655.0f, 450.0f, 310.0f, 75.0f},
        {655.0f, 550.0f, 310.0f, 75.0f},
        {655.0f, 650.0f, 310.0f, 75.0f}
    };

    Texture2D backgroundTexture = LoadTexture("assets/background.png");         //load texture in VRAM
    Texture2D logoTexture = LoadTexture("assets/Logo.png");


    Texture2D buttonEncyclopediaTexture = LoadTexture("assets/Menu/Buttons/EncyclopediaButton.png");           //Buttons' Texture
    Texture2D buttonQuizTexture = LoadTexture("assets/Menu/Buttons/QuizButton.png");
    Texture2D buttonskeletonTexture = LoadTexture("assets/Menu/Buttons/SkeletonButton.png");
    Texture2D buttonExitTexture = LoadTexture("assets/Menu/Buttons/ExitButton.png");

    Texture2D buttonТextures[4] = {                     //arranging textures in a struct
        buttonEncyclopediaTexture,
        buttonQuizTexture,
        buttonskeletonTexture,
        buttonExitTexture,
    };

    Texture2D soundOnIconTexture = LoadTexture("assets/speaker.png");           //sound icon textures
    Texture2D soundOffIconTexture = LoadTexture("assets/mute.png");

    Vector2 mainMenuTexturePosition = { 0, 0 };
    Vector2 logoTexturePosition = { 609, 32 };          
    Vector2 buttonPosition[4] = {
        {648.0f, 343.0f},
        {648.0f, 443.0f},
        {648.0f, 543.0f},
        {648.0f, 643.0f}
    };



    Texture2D customCursor = LoadTexture("assets/cursor.png");         //load cursor texture
    Vector2 cursorPosition;                                         //declare cursor position Vector2 struct
    Vector2 soundIconTexturePosition = { 1500.0f, 800.0f };


    Texture2D encyclopediaPage1 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia1.png");
    Texture2D encyclopediaPage2 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia2.png");
    Texture2D encyclopediaPage3 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia3.png");
    Texture2D encyclopediaPage4 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia4.png");
    Texture2D encyclopediaPage5 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia5.png");
    Texture2D encyclopediaPage6 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia6.png");
    Texture2D encyclopediaPage7 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia7.png");
    Texture2D encyclopediaPage8 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia8.png");
    Texture2D encyclopediaPage9 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia9.png");
    Texture2D encyclopediaPage10 = LoadTexture("assets/Menu/Encyclopedia/Encyclopedia10.png");

    Texture2D encyclopediaPages[10] = {
        encyclopediaPage1,
        encyclopediaPage2,
        encyclopediaPage3,
        encyclopediaPage4,                      //arrange encyclopedia in an array
        encyclopediaPage5,
        encyclopediaPage6,
        encyclopediaPage7,
        encyclopediaPage8,
        encyclopediaPage9,
        encyclopediaPage10
    };

    Rectangle toMenuInEncyclopediaButton = { 1194.0f, 806.0f, 291.0f, 87.0f };
    Rectangle encyplopediaMenuButton = { 1436.0f, 746.0f, 146.0f, 54.0f};


    SetTargetFPS(240);               //FPS locked at 240

    HideCursor();

    while (!WindowShouldClose())    //main loop
    {
        // Update
        //----------------------------------------------------------------------------------
        cursorPosition = GetMousePosition();        //cursor position
        cursorPosition.x -= 3;


        SetWinowsRes(screenWidth, screenHeight);          //function for changing fullscreen mode

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[0]) && isInMenu)
        {
            encyclopedia = !encyclopedia;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                isInMenu = !isInMenu;
            }
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[1]) && isInMenu)
        {
            quiz = !quiz;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                isInMenu = !isInMenu;
            }
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[2]) && isInMenu)
        {
            skeleton = !skeleton;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                isInMenu = !isInMenu;
            }
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && isMouseInSoundIconPosition())
        {
            hoverSoundButton = !hoverSoundButton;
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[3]) && isInMenu && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            isExitButtonPressed = !isExitButtonPressed;
        }

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
            if (!hoverSoundButton)
            {
                DrawTextureV(soundOffIconTexture, soundIconTexturePosition, WHITE);
            }
            else
            {
                DrawTextureV(soundOnIconTexture, soundIconTexturePosition, WHITE);
            }
        }
        else
        {
            if (encyclopedia)
            {
                
                DrawTextureV(encyclopediaPages[i], mainMenuTexturePosition, RAYWHITE);
                if (CheckCollisionPointRec(cursorPosition, toMenuInEncyclopediaButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && i >= 1)
                {
                    isInMenu = !isInMenu;
                }
                else if (IsKeyPressed(KEY_RIGHT))
                {
                    i++;
                    if (i == 9)
                    {
                        isInMenu = !isInMenu;
                        i = 0;
                    }
                }
                else if (IsKeyPressed(KEY_LEFT) && i >= 1)
                {
                    i--;
                }
                else if(IsKeyPressed(KEY_LEFT) && i == 0)
                {
                    isInMenu = !isInMenu;
                }
            }
            /*else if (quiz)
            {

            }
            else if(skeleton)
            {
                
            }*/
        }



        

        DrawTextureV(customCursor, cursorPosition, WHITE); //draw cursor texture

        EndDrawing();

        if (isExitButtonPressed)
        {
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}