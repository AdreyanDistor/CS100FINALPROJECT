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
    
    return 0;
}