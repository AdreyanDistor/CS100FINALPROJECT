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

void taskPageMenu(TaskListGUI& taskList) {
    int option;
    cout 
    << "TASK PAGE" << endl << endl

    << "1 - Add a Task" << endl
    << "2 - Delete a Task" << endl
    << "3 - Print a Task List" << endl //leads to print menu 
    << "4 - Edit a Task" << endl
    << "5 - Show Details" << endl
    << "6 - Mark Complete" << endl
    << "7 - Undo Delete" << endl
    << "8 - Back to Main Page" << endl << endl
   
    << "Enter option: " << endl;
    cin >> option;

    while (option != 8) {
        if (option == 1) { //add 
            cout << "Enter New Task Name: (ex: Lecture HomeWork)" << endl;
            string taskName;
            cin.ignore();
            getline(cin,taskName);
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
            cin.ignore();
            getline(cin,taskDescription);
            taskList.addTask(taskName, taskTag, taskDescription,taskDay,taskMonth,taskYear);
        } else if (option == 2) { //delete 
            cout << "Which task would you like to delete?" << endl;
            string task_toDeleteName;
            cin.ignore();
            getline(cin, task_toDeleteName);
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
            << "Printing Types" << endl 
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
                taskList.showByTag(taskTag);
            } else {
                taskList.showOverdue();
            }
        } else if (option == 4) { //edit
            string _name;
            cout << "Enter the name of the task you want to edit: " << endl;
            cin.ignore();
            getline(cin, _name);
            taskList.editTask(_name);
        } else if (option == 5) { //show details 
            string name;
            char key = -1;
          
            cout << "Which task would you like to view?" << endl;
            cin.ignore();
            getline(cin, name);
            TaskNode* taskToView = taskList.search(name);
            if (taskToView != nullptr) {
                while (key == -1) {
                if (taskToView->overdue == true) {
                    cout << "OVERDUE!\n" <<
                        "Name: " << taskToView->name << "\n" <<
                        "Due Date: " << taskToView->printDate() << "\n" <<
                        "Tag: " << taskToView->tag << "\n" <<
                        "Description:\n" <<
                        taskToView->description << "\n\n" <<

                        "Click any key to exit." << endl;
                } else {
                        cout << "Name: " << taskToView->name << "\n" <<
                        "Due Date: " << taskToView->printDate() << "\n" <<
                        "Tag: " << taskToView->tag << "\n" <<
                        "Description:\n" <<
                        taskToView->description << "\n\n" <<

                        "Click any key to exit." << endl;
                }
                    cin >> key;
                }
            } else {
                cout << "That task was not found\n\n";
            }
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
        << "5 - Show Details" << endl
        << "6 - Mark Complete" << endl
        << "7 - Undo Delete" << endl
        << "8 - Back to Main Page" << endl << endl
    
        << "Enter option: " << endl;
        cin >> option;
    }
}

void awardShopMenu(AwardListGUI& awardList) {
    int option;
    cout 
    << "AWARD SHOP" << endl << endl;
    awardList.displayAwards();
    cout
    << "1 - Add an Award" << endl
    << "2 - Delete an Award" << endl
    << "3 - Buy an Award" << endl
    << "4 - Use an Award" << endl
    << "5 - Back to Main Page" << endl << endl
   
    << "Enter option: " << endl;
    cin >> option;

    while (option != 5) {
        if (option == 1) { //add
            string _name;
            int _cost;
            cout << "Enter name of new award: " << endl;
            getline(cin, _name);
            cin.clear();
            cout << "Enter price of new award: " << endl;
            cin >> _cost;
            awardList.createAward(_name, _cost);
        } else if (option == 2) { //delete
            string _name;
            cout << "Enter name of award you want to delete: " << endl;
            getline(cin, _name);
            cin.clear();
            awardList.deleteAward(_name);
        } else if (option == 3) { //buy 
            string _name;
            int quantity;
            cout << "Enter name of award you want to buy: " << endl;
            getline(cin, _name);
            cin.clear();
            cout << "How many do you want to buy: " << endl;
            cin >> quantity;
            awardList.buyAward(_name, quantity);
        } else if (option == 4) { //use 
            string _name;
            cout << "Enter name of award you want to use: " << endl;
            getline(cin, _name);
            cin.clear();
            awardList.useAward(_name);
        }

        cout 
        << "AWARD SHOP" << endl << endl

        << "1 - Add an Award" << endl
        << "2 - Delete an Award" << endl
        << "3 - Buy an Award" << endl
        << "4 - Use an Award" << endl
        << "5 - Back to Main Page" << endl << endl
    
        << "Enter option: " << endl;
        cin >> option;
    }
}

void startMenu(TaskListGUI& taskList, AwardListGUI& awardList) {
    int option;
    cout << "TIME MANAGMENT" << endl << endl; //print the title 
    cout << "Points: 'CHORE' = 5 | 'ESSAY' =  10 | 'SHORT' = 7 | 'LONG_' = 12 | 'STUDY' = 7 | 'PROJT' = 20 | 'LAB__' = 7 | 'OTHER' = 0" << endl << endl;
    taskList.printList();

    cout 
    << "MAIN PAGE" << endl << endl

    << "1 - Tasks" << endl
    << "2 - Award Shop" << endl
    << "3 - Point Log" << endl
    << "4 - Quit Program" << endl << endl

    << "Enter option: " << endl;
    cin >> option;

    while (option != 4) {
        if (option == 1) { //task page 
            taskPageMenu(taskList);
        } else if (option == 2) { //award page 
            awardShopMenu(awardList);
        } else if (option == 3) { //point log 
            awardList.displayPointLog();
        } 

        cout 
        << "MAIN PAGE" << endl << endl

        << "1 - Tasks" << endl
        << "2 - Award Shop" << endl
        << "3 - Point Log" << endl
        << "4 - Quit Program" << endl << endl

        << "Enter option: " << endl;
        cin >> option;
    }
}

int main() {
  
    AwardListGUI awardList;
    TaskListGUI taskList;
    // set up
    taskList.importTasks("saved_files/TaskList.txt");
    awardList.importAwards("saved_files/AwardList.txt");
    awardList.importTotalPoints();
    taskList.markOverdue();
    
    startMenu(taskList, awardList);

    //saving data 
    taskList.exportTasks("saved_files/TaskList.txt");
    awardList.exportAwards("saved_files/AwardList.txt");
    awardList.exportTotalPoints();
    
    return 0;
}
