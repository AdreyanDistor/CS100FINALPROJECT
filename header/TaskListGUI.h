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
        void showOverdue();//displays tasks that are overdue
        void showTodayOnly(); // displays today’s tasks
        void sortByTag(string user_tag); //displays tasks of a specific tag
};

#endif