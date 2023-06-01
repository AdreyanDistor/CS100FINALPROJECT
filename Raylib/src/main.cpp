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

Screen currentScreen = Screen::TimeandDay;

void InitializeButtons()
{
    
}

bool IsMouseButtonPressedOnButton(const Button& button)
{
    return CheckCollisionPointRec(GetMousePosition(), button.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

//Time Day
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
                //draw
                break;
            case Screen::Main:
                
                break;
            case Screen::AwardShop:
                
                break;
            case Screen::AddAward:
                
                break;
            case Screen::HomeScreen:
                
                break;
            case Screen::EditTask:
                
                break;
            case Screen::CompletedTask:
                
                break;
        }
    }

    CloseWindow();

    return 0;
}
