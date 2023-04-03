#include <iostream>
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

    Texture2D buttonТextures[4] = {                     
        LoadTexture("assets/Menu/Buttons/EncyclopediaButton.png"),
        LoadTexture("assets/Menu/Buttons/QuizButton.png"),
        LoadTexture("assets/Menu/Buttons/SkeletonButton.png"),              //Buttons' Texture
        LoadTexture("assets/Menu/Buttons/ExitButton.png"),
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

    Texture2D encyclopediaPages[10] = {
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia1.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia2.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia3.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia4.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia5.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia6.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia7.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia8.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia9.png"),
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia10.png"),
    };

    int j = 0;
    Texture2D skeletonTextures[9] = {
        LoadTexture("assets/Menu/Skeleton/FrontSkeleton.png"),          // 0 is Front
        LoadTexture("assets/Menu/Skeleton/Skull.png"),
        LoadTexture("assets/Menu/Skeleton/Chest.png"),
        LoadTexture("assets/Menu/Skeleton/Arm.png"),
        LoadTexture("assets/Menu/Skeleton/Hand.png"),
        LoadTexture("assets/Menu/Skeleton/Leg.png"),
        LoadTexture("assets/Menu/Skeleton/BackSkeleton.png"),           //6 is Back
        LoadTexture("assets/Menu/Skeleton/Spine.png"),
        LoadTexture("assets/Menu/Skeleton/Pelvis.png"),
        
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

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[0]) && isInMenu && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            encyclopedia = !encyclopedia;
            isInMenu = !isInMenu;
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[1]) && isInMenu && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            quiz = !quiz;
            isInMenu = !isInMenu;
        }

        if (CheckCollisionPointRec(cursorPosition, underButtonRectangle[2]) && isInMenu && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            skeleton = !skeleton;
            isInMenu = !isInMenu;
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
                    encyclopedia = !encyclopedia;
                    isInMenu = !isInMenu;
                }
                else if (IsKeyPressed(KEY_RIGHT))
                {
                    i++;
                    if (i == 10)
                    {
                        i--;
                    }
                }
                else if (IsKeyPressed(KEY_LEFT) && i >= 1)
                {
                    i--;
                }
                else if(IsKeyPressed(KEY_LEFT) && i == 0)
                {
                    encyclopedia = !encyclopedia;
                    isInMenu = !isInMenu;
                }
            }
            else if (quiz)
            {

            }
            else if(skeleton)
            {
                printf("%i\n", j);
                DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);

                if (j == 0)             //Front Skeleton
                {
                    if (CheckCollisionPointRec(cursorPosition, Rectangle{ 0.0f, 768.0f, 309.0f, 100.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // checks if mouse is on menu button
                    {
                        isInMenu = !isInMenu;
                        skeleton = !skeleton;
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 800.0f, 150.0f, 45.0f, 40.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))    //check if mouse is on skull
                    {
                        j = 1;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);

                        if (CheckCollisionPointRec(cursorPosition, Rectangle{ 1460.0f, 10.0f, 125.0f, 115.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        {
                            break;
                        }
                        else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 710.0f, 710.0f, 590.0f, 130.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //DOES NOT FUNCTION PROPERLY
                        {
                            i = 3;
                            DrawTextureV(encyclopediaPages[i], mainMenuTexturePosition, WHITE);
                        }
                    }
                    else if (IsKeyPressed(KEY_RIGHT))
                    {
                        j = 6;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                }
                else if (j == 6)            //Back Skeleton
                {
                    if (CheckCollisionPointRec(cursorPosition, Rectangle{ 1277.0f, 768.0f, 309.0f, 100.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        isInMenu = !isInMenu;
                        skeleton = !skeleton;
                    }
                    if (IsKeyPressed(KEY_LEFT))
                    {
                        j = 0;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                }
            }
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