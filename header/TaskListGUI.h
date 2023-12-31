#ifndef TASKLISTGUI_H
#define TASKLISTGUI_H
#include "TaskList.h"
#include <iostream>
#include <fstream>
#include<ostream>
#include <ctime>
#include <string>
using namespace std;

class TaskListGUI : public TaskList {
    public:
        TaskListGUI() : TaskList() {}
        void showOverdue();//displays tasks that are overdue
        void showTodayOnly(); // displays today’s tasks
        void showByTag(string user_tag); //displays tasks of a specific tag
        void printOverdueMessage();
        void printList(); //prints entire list, could be added to a class called gui, or user input 

};

#endif