#include "../header/AwardList.h"
#include "../header/TaskList.h"
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
void mainMenu() {
    cout << "MAIN MENU" << endl << endl;;
    
    cout << "Where would you like to go?" << endl; //we can change the words
    cout << "1 - Tasks Page" << endl;
    cout << "2- Award Shop" << endl;
    cout << "3 - Point Log" << endl;
    cout << "4 - Exit Program" << endl << endl;;

    cout << "Enter choice: " << endl;
}

void taskPageMenu() {
    cout << "Task Page" << endl << endl;

    cout << "1 - Add a Task" << endl;
    cout << "2 - Delete a Task" << endl;
    cout << "3 - Print a Task List" << endl; //leads to print menu 
    cout << "4 - Edit a Task" << endl;
    //show details
    //mark complete
    //undo last delete
    //back to main page 
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
    
    return 0;
}