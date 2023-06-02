#include <raylib.h>
#include"../../header/AwardList.h";
#include"../../header/AwardListGui.h";
#include"../../header/TaskList.h";
#include"../../header/TaskListGUI.h";
enum class Screen
{
    TimeandDay,
    Main,
    AwardShop,
    AddAward,
    HomeScreen,
    EditTask,
    CompletedTask,

};

struct Button
{
    Rectangle bounds;
    Color idleColor;
    Color hoverColor;
    Color pressedColor;
    bool hovered;
    bool pressed;
};

struct textBox: Button
{
    string text;

};
//global variables 
Screen currentScreen = Screen::TimeandDay;
void InitializeButtons()
{
    
}


void UpdateTextInput(textBox& textBOX)
{
    if(IsMouseButtonPressedOnButton(textBOX))
    {
        int key = GetKeyPressed();
        while (key > 0)
        {
            if ((key >= 0) && (key <= 0) && (textBOX.text.length() < 16))
            {
                textBOX.text += static_cast<char>(key);
            }

            key = GetKeyPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && !textBOX.text.empty())
        {
            textBOX.text.pop_back();
        }
    }
    
}

bool IsMouseButtonPressedOnButton(const Button& button)
{
    return CheckCollisionPointRec(GetMousePosition(), button.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

//Time Day
int currentDay;
int currentMonth;
int currentYear;
textBox day;
textBox month;
textBox year;

// void UpdateMainMenu()
// {
//     startButton.hovered = CheckCollisionPointRec(GetMousePosition(), startButton.bounds);

//     if (IsMouseButtonPressedOnButton(startButton))
//     {
//         currentScreen = ScreenState::Game;
//     }
// }

// void DrawMainMenu()
// {
//     BeginDrawing();
//     ClearBackground(RAYWHITE);

//     DrawRectangleRec(startButton.bounds, startButton.hovered ? startButton.hoverColor : startButton.idleColor);
//     DrawText("Start Game", static_cast<int>(startButton.bounds.x) + 10, static_cast<int>(startButton.bounds.y) + 10, 20, BLACK);

//     EndDrawing();
// }
void UpdateTimeandDay()
{
    
}

void DrawTimeandDay()
{

}

//Main
void UpdateMain()
{

}

void DrawMain()
{

}

//Award Shop
void UpdateAwardShop()
{

}

void DrawAwardShop()
{

}

//Add Award
void UpdateAddAward()
{

}

void DrawAddAward()
{

}

//HomeScreen
void UpdateHomeScreen()
{

}

void DrawHomeScreen()
{

}

//EditTask
void UpdateEditTask()
{

}

void DrawEditTask()
{

}

//CompletedTask
void UpdateCompletedTask()
{

}

void DrawCompletedTask()
{

}

// void UpdateMainMenu()
// {
//     startButton.hovered = CheckCollisionPointRec(GetMousePosition(), startButton.bounds);

//     if (IsMouseButtonPressedOnButton(startButton))
//     {
//         currentScreen = ScreenState::Game;
//     }
// }

// void DrawMainMenu()
// {
//     BeginDrawing();
//     ClearBackground(RAYWHITE);

//     DrawRectangleRec(startButton.bounds, startButton.hovered ? startButton.hoverColor : startButton.idleColor);
//     DrawText("Start Game", static_cast<int>(startButton.bounds.x) + 10, static_cast<int>(startButton.bounds.y) + 10, 20, BLACK);

//     EndDrawing();
// }



int main()
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Task Manager");

    InitializeButtons();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
            case Screen::TimeandDay:
                //update
                UpdateTimeandDay();
                //draw
                DrawTimeandDay();
                break;
            case Screen::Main:
                UpdateMain();
                DrawMain();
                break;
            case Screen::AwardShop:
                UpdateAwardShop();
                DrawAwardShop();
                break;
            case Screen::AddAward:
                UpdateAddAward();
                DrawAddAward();
                break;
            case Screen::HomeScreen:
                UpdateHomeScreen();
                DrawHomeScreen();
                break;
            case Screen::EditTask:
                UpdateEditTask();
                DrawEditTask();
                break;
            case Screen::CompletedTask:
                UpdateCompletedTask();
                DrawCompletedTask();
                break;
        }
    }

    CloseWindow();

    return 0;
}
