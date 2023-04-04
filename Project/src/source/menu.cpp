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

    //quiz variables  // Define the current question and answer options
    int currentQuestion = 0;
    int currentAnswer = -1; // -1 means no answer has been selected yet
    bool answered = false;
    bool correct = false;
    const int numQuestions = 4;
    Color beforeAnswer = { 0xEA, 0xDD, 0xCA, 0xCA };//using hex colors
    Color afterAnswer = { 0xDB, 0xCF, 0xBD, 0xBD };//using hex colors

    std::string questions[] = { "What is the capital of France?", "What is the largest country in the world?",
                         "Who invented the telephone?", "What is the chemical symbol for gold?" };
    std::string answers[][4] = { {"Paris", "Berlin", "Madrid", "London"}, {"Russia", "China", "USA", "Canada"},
                           {"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Henry Ford"}, {"Au", "Ag", "Fe", "Hg"} };
    int correctAnswers[] = { 0, 1, 0, 0 }; // The index of the correct answer for each question

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

    Texture2D quizTexture = LoadTexture("assets/whiteboardQuiz.png");
    quizTexture.width = 1600;
    quizTexture.height = 900;
    Vector2 quizTexturePosition = { 0,0 };

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
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia4.png"),          //Skull i = 3
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia5.png"),          //Arms i = 4
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia6.png"),          //Chest i = 5
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia7.png"),          //Hand i = 6
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia8.png"),          //Spine i = 7
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia9.png"),          //Pelvis i = 8
        LoadTexture("assets/Menu/Encyclopedia/Encyclopedia10.png"),         //Legs i = 9
    };

    int j = 0;
    Texture2D skeletonTextures[9] = {
        LoadTexture("assets/Menu/Skeleton/FrontSkeleton.png"),          // 0 is Front Skeleton
        LoadTexture("assets/Menu/Skeleton/Skull.png"),                  // 1 is Skull
        LoadTexture("assets/Menu/Skeleton/Chest.png"),                  // 2 is Chest
        LoadTexture("assets/Menu/Skeleton/Arm.png"),                    // 3 is Arm
        LoadTexture("assets/Menu/Skeleton/Hand.png"),                   // 4 is Hand
        LoadTexture("assets/Menu/Skeleton/Leg.png"),                    // 5 is Leg
        LoadTexture("assets/Menu/Skeleton/BackSkeleton.png"),           // 6 is Back Skeleton
        LoadTexture("assets/Menu/Skeleton/Spine.png"),                  // 7 is Spine
        LoadTexture("assets/Menu/Skeleton/Pelvis.png"),                 // 8 is Pelvis
        
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
            currentQuestion = 0;
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
                DrawTextureV(quizTexture, quizTexturePosition, WHITE);
                DrawText(questions[currentQuestion].c_str(), 300, 190, 20, BLACK);
                for (int i = 0; i < 4; i++) {
                    Rectangle option = { 300, 260 + i * 50, 700, 40 };
                    DrawRectangleRec(option, (i == currentAnswer ? afterAnswer : beforeAnswer));
                    DrawText(answers[currentQuestion][i].c_str(), 310, 270 + i * 50, 20, BLACK);
                }

                // Show correct/incorrect answer feedback if answered
                if (answered) {

                    if (correct) {
                        DrawText("Correct!", 300, 500, 30, GREEN);
                    }
                    else {
                        DrawText("Incorrect.", 300, 470, 30, RED);
                        DrawText(("The correct answer was " + answers[currentQuestion][correctAnswers[currentQuestion]]).c_str(), 300, 505, 20, DARKGRAY);
                    }
                }

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    int mouseY = GetMouseY();
                    if (mouseY >= 270 && mouseY < 295) currentAnswer = 0;
                    else if (mouseY >= 300 && mouseY < 335) currentAnswer = 1;
                    else if (mouseY >= 365 && mouseY < 385) currentAnswer = 2;
                    else if (mouseY >= 400 && mouseY < 450) currentAnswer = 3;
                }
                if (IsKeyPressed(KEY_ENTER)) {
                    // Check if the answer is correct
                    if (!answered) {
                        if (currentAnswer == correctAnswers[currentQuestion]) {
                            correct = true;
                        }
                        else {
                            correct = false;
                        }
                        answered = true;
                    }
                    else {
                        // Move on to the next question
                        currentQuestion++;
                        currentAnswer = -1;
                        answered = false;
                        if (currentQuestion >= numQuestions)
                        {
                            isInMenu = !isInMenu;
                            quiz = !quiz;
                        }
                    }
                }
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
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);      //Drawing the skull

                        if (CheckCollisionPointRec(cursorPosition, Rectangle{ 1460.0f, 10.0f, 140.0f, 125.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //checks if mouse is on X button
                        {
                            isInMenu = !isInMenu;
                            skeleton = !skeleton;
                        }
                        else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 710.0f, 710.0f, 590.0f, 130.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //DOES NOT FUNCTION PROPERLY
                        {
                            i = 3;
                            DrawTextureV(encyclopediaPages[i], mainMenuTexturePosition, WHITE);
                        }                    
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 775.0f, 315.0f, 45.0f, 45.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //checks if mouse is on chest
                    {
                        j = 2;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 630.0f, 335.0f, 50.0f, 40.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //checks if mouse is on arm
                    {
                        j = 3;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 925.0f, 525.0f, 45.0f, 45.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //checks if mouse is on hand
                    {
                        j = 4;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 810.0f, 630.0f, 50.0f, 40.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     //checks if mouse is on leg
                    {
                        j = 5;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                    else if (IsKeyPressed(KEY_RIGHT))
                    {
                        j = 6;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                }
                else if (j == 6)            //Back Skeleton
                {
                    if (CheckCollisionPointRec(cursorPosition, Rectangle{ 1277.0f, 768.0f, 309.0f, 100.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))     // checks if mouse is on menu button
                    {
                        isInMenu = !isInMenu;
                        skeleton = !skeleton;
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 735.0f, 260.0f, 50.0f, 40.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        j = 7;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                    else if (CheckCollisionPointRec(cursorPosition, Rectangle{ 850.0f, 445.0f, 50.0f, 45.0f }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        j = 8;
                        DrawTextureV(skeletonTextures[j], mainMenuTexturePosition, WHITE);
                    }
                    else if (IsKeyPressed(KEY_LEFT))
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