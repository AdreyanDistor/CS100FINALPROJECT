#include "../header/AwardListGUI.h"
#include "../header/TaskListGUI.h"
#include<iostream>
#include<fstream>
#include <ostream>
#include<string>
#include<iomanip>
#include<vector>
#include<time.h>
#include<ctime>
using namespace std;

//global


int main() {
    AwardListGUI awardList;
    TaskListGUI taskList;
    taskList.importTasks();
    awardList.importAwards();
    
    //AddTask
    cout << "Enter Task Name: (ex: Lecture HomeWork)" << endl << endl;
    string taskName;
    getline(cin,taskName);
    cin.clear();
    cout << "Choose Tag:" << endl <<
    "1 - Chore" << endl <<
    "2 - Essay" << endl <<
    "3 - Short Assignment" << endl <<
    "4 - Long Assignment" << endl <<
    "5 - Studying" << endl <<
    "6 - Project" << endl <<
    "7 - Lab" << endl <<
    "8 - Other" << endl;
    string taskTag;
    cin >> taskTag;
    if(taskTag == "1")
    {
        taskTag = "chore";
    }
    else if(taskTag == "2")
    {
        taskTag = "essay";
    }
    else if(taskTag == "3")
    {
        taskTag = "short_assign";
    }
    else if(taskTag == "4")
    {
        taskTag = "long_assign";

    }
    else if(taskTag == "5")
    {
        taskTag = "studying";

    }
    else if(taskTag == "6")
    {
        taskTag = "project";
    }
    else if(taskTag == "7")
    {
        taskTag = "lab";
    }
    else
    {
        taskTag = "other";
    }
    cout << endl << "Enter Due Date - Month: (ex: 11)" << endl;
    int taskMonth;
    cin >> taskMonth;
    cout << endl << "Enter Due Date - Day: (ex: 23)" << endl;
    int taskDay;
    cin >> taskDay;
    cout << endl << "Enter Due Date - Year: (ex: 2023)" << endl;
    int taskYear;
    cin >> taskYear;
    cout << endl << "Enter Description: ";
    string taskDescription;
    getline(cin,taskDescription);
    cin.clear();
    taskList.addTask(taskName, taskTag, taskDescription,taskDay,taskMonth,taskYear);
    
    //DeleteTaskScreen
    cout << "Which task would you like to delete?" << endl;
    string task_toDeleteName;
    getline(cin, task_toDeleteName);
    cin.clear();
    TaskNode* task_toDelete = taskList.search(task_toDeleteName);
    if(task_toDelete != nullptr)
    {
        taskList.deleteTask(task_toDeleteName);
    }
    else
    {
        cout << "Not here bob" << endl;
    }

    //UndoDeleteTaskScreen
    taskList.undoDeleteTask();

    //PointLogScreen
    awardList.displayPointLog();


    //Show Task Details Screen
    string name;
    char key = -1;
    cout << "Which task would you like to view?" << endl;
    getline(cin, name);
    TaskNode* taskToView = taskList.search(name);
    if (tasktoView != nullptr) {
        while (key == -1) {
        if (tasktoView->overdue == true) {
            cout << "OVERDUE!\n" <<
                "Name: " << taskToView->name << "\n" <<
                "Due Date: " << taskToView->printDate() << "\n" <<
                "Tag: " << taskToView->tag << "\n" <<
                "Description:\n" <<
                taskToView->Description << "\n\n" <<

                "Click any key to exit." << endl;
        } else {
                cout << "Name: " << taskToView->name << "\n" <<
                "Due Date: " << taskToView->printDate() << "\n" <<
                "Tag: " << taskToView->tag << "\n" <<
                "Description:\n" <<
                taskToView->Description << "\n\n" <<

                "Click any key to exit." << endl;
        }
            cin >> key;
        }
    } else {
        cout << "That task was not found\n\n";
    }
    return 0;


    // mark task completed screen
    string completedTaskName;
    cout << "Which task have you completed?" << endl;
    getline(cin, completedTaskName);
    // make sure this function can check for invalid input
    TaskList.markTaskCompleted(completedTaskName);
}