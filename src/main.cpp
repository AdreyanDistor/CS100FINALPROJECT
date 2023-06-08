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
    /*Imports total_points*/
       TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 4, 2012);
    list.addTask("two", "chore", "second one", 2, 2, 2022);
    list.addTask("three", "chore", "third one", 3, 3, 2012);
    cout << list.printList(); 
    return 0;
}