#include "../raylib/raylib/src/raylib.h"
#include "../../header/AwardList.h"
#include "../../header/AwardListGUI.h"
#include "../../header/TaskList.h"
#include "../../header/TaskListGUI.h"
#include <vector>
using namespace std;
#include <string>
#define MAX_INPUT_CHARS 20
#include <cstring>

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Start Screen");

    char timeInput[MAX_INPUT_CHARS + 1] = "\0";
    char dayInput[MAX_INPUT_CHARS + 1] = "\0";
    bool goToNextScreen = false;

    Rectangle nextButtonRec = { screenWidth / 2 - 50, screenHeight - 100, 100, 50 };

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();

            if (CheckCollisionPointRec(mousePos, nextButtonRec))
            {
                goToNextScreen = true;
            }
        }

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Enter Time:", screenWidth / 2 - 80, screenHeight / 2 - 20, 20, BLACK);
        DrawText(timeInput, screenWidth / 2 - 80, screenHeight / 2 + 10, 20, BLACK);

        DrawText("Enter Day:", screenWidth / 2 - 80, screenHeight / 2 + 60, 20, BLACK);
        DrawText(dayInput, screenWidth / 2 - 80, screenHeight / 2 + 90, 20, BLACK);

        DrawRectangleRec(nextButtonRec, LIGHTGRAY);
        DrawText("Next", nextButtonRec.x + 20, nextButtonRec.y + 10, 20, BLACK);

        EndDrawing();

        // Input
        if (!goToNextScreen)
        {
            int key = GetKeyPressed();

            if (key != KEY_NULL && strlen(timeInput) < MAX_INPUT_CHARS)
            {
                timeInput[strlen(timeInput)] = (char)key;
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                int length = strlen(timeInput);
                if (length > 0)
                {
                    timeInput[length - 1] = '\0';
                }
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                strcpy(dayInput, timeInput);
                memset(timeInput, '\0', sizeof(timeInput));
            }
        }

        // Go to next screen
        if (goToNextScreen)
        {
            // Add code to transition to the next screen
            break;
        }
    }

    // De-Initialization
    CloseWindow();

    return 0;
}