#include "../header/AwardListGUI.h"
#include "../header/TaskListGUI.h"
#include<iostream>
#include<fstream>
#include<ostream>
#include<string>
#include<iomanip>
#include<vector>
#include<time.h>
#include<ctime>
using namespace std;

void startMenu(TaskListGUI& taskList, AwardListGUI& awardList) {
    int option;
    cout << "TIME MANAGMENT" << endl << endl; //print the title 
    cout << "Points: 'CHORE' = 5 | 'ESSAY' =  10 | 'SHORT' = 7 | 'LONG_' = 12 | 'STUDY' = 7 | 'PROJT' = 20 | 'LAB__' = 7 | 'OTHER' = 0" << endl << endl;
    cout 
    << "MAIN PAGE" << endl << endl

    << "1. Tasks" << endl
    << "2. Award Shop" << endl
    << "3. Point Log" << endl
    << "4. Quit Program" << endl << endl

    << "Enter option: " << endl;
    cin >> option;

    while (option != 4) {
        if (option == 1) { //task page 
            taskPageMenu();
        } else if (option == 2) { //award page 
            awardList.displayAwards();
            cout << endl;
            awardShopMenu();
        } else if (option == 3) { //point log 
            awardList.displayPointLog();
        } 

        cout 
        << "MAIN PAGE" << endl << endl

        << "1. Tasks" << endl
        << "2. Award Shop" << endl
        << "3. Point Log" << endl
        << "4. Quit Program" << endl << endl

        << "Enter option: " << endl;
        cin >> option;
    }
}


void taskPageMenu(TaskListGUI& taskList) {
    int option;
    cout 
    << "TASK PAGE" << endl << endl

    << "1 - Add a Task" << endl
    << "2 - Delete a Task" << endl
    << "3 - Print a Task List" << endl //leads to print menu 
    << "4 - Edit a Task" << endl
    << "5. Show Details" << endl
    << "6. Mark Complete" << endl
    << "7. Undo Delete" << endl
    << "8 - Back to Main Page" << endl << endl
   
    << "Enter option: " << endl;
    cin >> option;

    while (option != 8) {
        if (option == 1) { //add 
            cout << "Enter New Task Name: (ex: Lecture HomeWork)" << endl << endl;
            string taskName;
            getline(cin,taskName);
            cin.clear();
            cout << "1 - Chore" << endl <<
            "2 - Essay" << endl <<
            "3 - Short Assignment" << endl <<
            "4 - Long Assignment" << endl <<
            "5 - Studying" << endl <<
            "6 - Project" << endl <<
            "7 - Lab" << endl <<
            "8 - Other" << endl << 
            "Choose Tag:" << endl << endl;
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
        } else if (option == 2) { //delete 
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
                cout << "Error: this task does not exist." << endl;
            }
        } else if (option == 3) { //printing 
            int choice;
            cout 
            << "Printing Types" << endl <<
            << "1 - Show Today Only" << endl
            << "2 - Show by Tag" << endl
            << "3 - Show Overdue" << endl << endl
            << "Enter option: " << endl;
            cin >> choice;
            
            if (option == 1) {
                taskList.showTodayOnly();
            } else if (option == 2) {
                cout << "1 - Chore" << endl <<
                "2 - Essay" << endl <<
                "3 - Short Assignment" << endl <<
                "4 - Long Assignment" << endl <<
                "5 - Studying" << endl <<
                "6 - Project" << endl <<
                "7 - Lab" << endl <<
                "8 - Other" << endl << 
                "Choose Tag:" << endl << endl;
                int taskTag;
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
                taskList.showByTag(taskTag);
            } else {
                taskList.showOverdue();
            }
        } else if (option == 4) { //edit
            string _name;
            cout << "Enter the name of the task you want to edit: " << endl;
            getline(cin, _name);
            cin.clear();
            taskList.editTask(_name);
        } else if (option == 5) { //show details 
            string _name;
            cout << "Enter the name of which task you want to see the details of: " << endl;
            getline(cin, _name);
            cin.clear();
            TaskNode* curr = search(_name);
            //display details 
        } else if (option == 6) { //mark complete
            string _name;
            cout << "Enter the name of the task you want to mark complete: " << endl;
            getline(cin, _name);
            cin.clear();
            //mark complete
        } else if (option == 7) {  //undo delete 
            taskList.undoDeleteTask();
        }
        cout 
        << "TASK PAGE" << endl << endl

        << "1 - Add a Task" << endl
        << "2 - Delete a Task" << endl
        << "3 - Print a Task List" << endl 
        << "4 - Edit a Task" << endl
        << "5. Show Details" << endl
        << "6. Mark Complete" << endl
        << "7. Undo Delete" << endl
        << "8 - Back to Main Page" << endl << endl
    
        << "Enter option: " << endl;
        cin >> option;
    }
}

void awardShopMenu() {
    int option;
    cout 
    << "AWARD SHOP" << endl << endl

    << "1 - Add an Award" << endl
    << "2 - Delete an Award" << endl
    << "4 - Buy an Award" << endl
    << "5 - Use an Award" << endl
    << "8 - Back to Main Page" << endl << endl
   
    << "Enter option: " << endl;
    cin >> option;
}

int main() {
    AwardListGUI awardList;
    TaskListGUI taskList;
    /*Imports total_points*/
    taskList.importTasks();
    awardList.importAwards();
    taskList.markOverdue();
    
    startMenu();
    
    return 0;
}