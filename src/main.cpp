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

void startMenu() {
    cout 
    << "Enter menu choice: " << endl
    << "1. Tasks" << endl
    << "2. Award Shop" << endl
    << "3. Point Log" << endl
    << "4. Quit" << endl;
}

void taskMenu() {
    cout 
    << "1. Add" << endl
    << "2. Delete" << endl
    << "3. Show By Type" << endl
    << "4. Edit" << endl
    << "5. Show Details" << endl
    << "6. Mark Complete" << endl
    << "7. Undo Delete" << endl;
}

int main() {
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