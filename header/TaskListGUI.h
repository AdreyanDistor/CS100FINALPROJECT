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
        string showOverdue(TaskList list);//displays tasks that are overdue
        string showTodayOnly(TaskList list,int day, int month, int year); // displays today’s tasks
        string sortByTag(TaskList list, string user_tag); //displays tasks of a specific tag
};

#endif