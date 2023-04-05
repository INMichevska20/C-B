#include "raylib.h"
#include "../headers/settings.hpp"

bool isMouseInSoundIconPosition()
{
    return (GetMouseX() >= 1480 && GetMouseX() <= 1580 && GetMouseY() >= 780 && GetMouseY() <= 880);
}

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