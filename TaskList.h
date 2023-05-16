#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include<string>
using namespace std;

struct TaskNode {
    enum tags
    string title;
    int month; //00
    int day; //00
    int year; //00
    string description;
    string tag;
    bool done;
    int time;
    bool overdue;
    TaskNode* next;
    string exportTask()
    {
        string isDone;
        string isOverdue;
        if(done == true)
        {
            isDone = "true";
        }
        else
        {
            isDone = "false";
        }
        if(overdue == true)
        {
            isOverdue = "true";
        }
        else
        {
            isOverdue = "false";
        }
        string ouput = title + '`' + description + '`' + tag + '`' + isDone + '`' + to_string(month) + '`' + to_string(day) + '`' + to_string(year) + '`' + isOverdue + '`' + to_string(time);
    };
    int markCompleted()
    {
        
    }
    TaskNode(string name, int d, int m, int y, string des, string tag, int dueTime) : title(name), month(m), day(d), year(y),
        description(des), tag(tag), time(dueTime), done(false), overdue(false), next(nullptr) {}

};

//enum tags{};

class TaskList {
    private:
        TaskNode* head;
        int totalPoints;
    public:
        TaskList();
        ~TaskList();
        void addTask(string name);
        void deleteTask(string name);
        void importTasks(ifstream& file);
        void exportTasks(ofstream& file);

};

#endif