#ifndef TASKLISTGUI_H
#define TASKLISTGUI_H
#include "TaskList.h"
#include <iostream>
#include <fstream>
#include<ostream>
#include <ctime>
#include "TaskList.h"
using namespace std;

class TaskListGUI : public TaskList {
    public:
        string showOverdue();//displays tasks that are overdue
        string showTodayOnly(int day, int month, int year); // displays today’s tasks
        string sortByTag(string user_tag); //displays tasks of a specific tag
};

#endif