#include "../header/TaskList.h"
#include <iostream>
#include <string>
using namespace std;

TaskList::TaskList()
{
    head = nullptr;
    tail = nullptr;
    recent_deleted_Task = nullptr;
}

TaskList::~TaskList()
{
    TaskNode* currNode = head;
    while(currNode != nullptr)
    {
        TaskNode* tempNode = nullptr;
        tempNode = currNode;
        currNode = currNode->next;
        delete tempNode;
    }
}

void TaskList::showOverdue(char* tm) {
    TaskNode* curr = head;
    string time = tm;
    string monthStr = time.substr(4, 3);
    int currDay = stoi(time.substr(8, 2));
    int currMonth = 0;
    int currYear = stoi(time.substr(20, 4));
    
    if (monthStr == "Jan") {
        currMonth = 1;
    } else if (monthStr == "Feb") {
        currMonth = 2;
    } else if (monthStr == "Mar") {
        currMonth = 3;
    } else if (monthStr == "Apr") {
        currMonth = 4;
    } else if (monthStr == "May") {
        currMonth = 5;
    } else if (monthStr == "Jun") {
        currMonth = 6;
    } else if (monthStr == "Jul") {
        currMonth = 7;
    } else if (monthStr == "Aug") {
        currMonth = 8;
    } else if (monthStr == "Sep") {
        currMonth = 9;
    } else if (monthStr == "Oct") {
        currMonth = 10;
    } else if (monthStr == "Nov") {
        currMonth = 11;
    } else if (monthStr == "Dec") {
        currMonth = 12;
    }

    while (curr != nullptr) {
        if (curr->year > currYear) {
            curr->overdue = true;
        } else if (curr->month > currMon) {
            curr->overdue = true;
        } else if (curr->day > currDay) {
            curr->overdue = true;
        }
        curr = curr->next;
    }
    //GUI stuff to show tasks as red 
}

// COULD ADD TO GUI CLASS
void TaskList::printList()
{
    int i = 1;
    TaskNode* currNode = head;
    while (currNode !=nullptr)
    {
        cout << i << ". " << currNode->exportTask() << endl;
        currNode = currNode->next; 
        i++;
    }
}