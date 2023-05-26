#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
using namespace std;

struct TaskNode {
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
    void exportTask();
    TaskNode(string name, int d, int m, int y, string des, string tag, int dueTime) : title(name), month(m), day(d), year(y),
        description(des), tag(tag), time(dueTime), done(false), overdue(false), next(nullptr) {}
};

class TaskList {
    private:
        TaskNode* head;
        int totalPoints;
    public:
        void addTask(string name);
        void deleteTask(string name);

};

#endif