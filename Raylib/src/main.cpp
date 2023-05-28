#include "../raylib/raylib/src/raylib.h"

#include <vector>
using namespace std;
#include <string>
int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Infinite Scroll Example");

    int scrollOffset = 0;         // Vertical scroll offset
    int buttonHeight = 40;        // Height of each button
    int buttonSpacing = 10;       // Spacing between buttons
    int visibleButtons = screenHeight / (buttonHeight + buttonSpacing);  // Number of buttons visible on the screen at a time

    std::vector<std::string> buttonNames;  // Vector to store the names of the buttons
    int totalButtons = visibleButtons;     // Total number of buttons to generate initially

    // Generate initial buttons
    for (int i = 0; i < totalButtons; i++)
    {
        buttonNames.push_back("Button " + std::to_string(i));
    }

    while (!WindowShouldClose())
    {
        // Handle scrolling input with mouse wheel
        scrollOffset += GetMouseWheelMove() * 3;

        // Generate more buttons if scrolling down
        if (scrollOffset > buttonNames.size() - visibleButtons)
        {
            int numButtonsToGenerate = scrollOffset - (buttonNames.size() - visibleButtons);

            for (int i = 0; i < numButtonsToGenerate; i++)
            {
                buttonNames.push_back("Button " + std::to_string(buttonNames.size()));
            }
        }

        // Clear the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Render the visible buttons based on the scroll offset
        int startIndex = scrollOffset;
        int endIndex = startIndex + visibleButtons;

        for (int i = startIndex; i < endIndex; i++)
        {
            // Check if the button index is within the total number of buttons
            if (i < buttonNames.size())
            {
                // Calculate the button position based on the index and scroll offset
                int buttonY = (i - startIndex) * (buttonHeight + buttonSpacing);

                // Render the button
                DrawRectangle(0, buttonY, screenWidth, buttonHeight, LIGHTGRAY);
                DrawText(buttonNames[i].c_str(), 10, buttonY + 10, 20, DARKGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
