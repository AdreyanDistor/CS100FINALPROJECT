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
        }
    }
}


void taskPageMenu() {
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
}

void awardShopMenu() {
    cout 
    << "AWARD SHOP" << endl << endl

    << "1 - Add an Award" << endl
    << "2 - Delete an Award" << endl
    << "4 - Buy an Award" << endl
    << "5 - Use an Award" << endl
    << "8 - Back to Main Page" << endl << endl
   
    << "Enter option: " << endl;
}

void printingMenu() {
    //show today only
    //2 show overdue
    // show specific tag
    //show entire list
    //exit 
}
int main() {
    /*Imports total_points*/
    AwardList myAwardList;
    TaskListGUI myTaskList; 
    
    startMenu();
    int choice = 0;
    cin >> choice;
    if(choice == 1){
        //print task screen
    }
    else if(choice == 2) {
        //print awards screen
    }
    else if(choice == 3) {
        //print point log
    }
    return 0;
}