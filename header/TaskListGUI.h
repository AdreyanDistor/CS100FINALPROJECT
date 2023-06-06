#ifndef TASKLISTGUI_H
#define TASKLISTGUI_H
#include "TaskList.h"
#include <iostream>
#include <fstream>
#include<ostream>
#include <ctime>
using namespace std;

class TaskListGUI : public TaskList {
    public:
        void showOverdue(char* tm);//displays tasks that are overdue
        string showTodayOnly(int day, int month, int year); // displays today’s tasks
        string sortByTag(string user_tag); //displays tasks of a specific tag
};

#endif