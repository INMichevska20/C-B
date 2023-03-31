#include <iostream>
#include "raylib.h"

#include "../headers/raygui.h"
#include "../headers/button.hpp"
#include "../headers/menu.hpp"
#include "../headers/settings.hpp"

void menu()
{
    const int screenWidth = 1600;       //fixed window resolution
    const int screenHeight = 900;
    

    InitWindow(screenWidth, screenHeight, "Project B-C");       //Initializing OpenGL window



    Texture2D mainMenuTexture = LoadTexture("assets/background.png");         //load texture in VRAM
    Vector2 mainMenuTexturePosition = {0, 0};
    
    // Does NOT work for now: GuiLoadStyleButton();

    Texture2D customCursor = LoadTexture("assets/customCursor.png");         //load texture in VRAM
    Vector2 cursorPosition = { -100.0f, -100.0f };
    
    
    SetTargetFPS(240);               //FPS locked at 240

    
    HideCursor();
    while (!WindowShouldClose())    //main loop
    {
        // Update
        //----------------------------------------------------------------------------------
        cursorPosition = GetMousePosition();        //cursor position
        SetWinowsRes(screenWidth, screenHeight);          //function for changing fullscreen mode
       
        

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            
            ClearBackground(WHITE);
            DrawTextureV(mainMenuTexture, mainMenuTexturePosition, WHITE);
            //DrawRectangle(660, 400, 240, 200, RED);           //FOR TESTING PURPOSES!!!
            DrawTextureV(customCursor, cursorPosition, WHITE);

        EndDrawing();
    } 

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}