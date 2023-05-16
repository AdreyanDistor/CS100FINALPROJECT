#include "TaskList.h"
#include <iostream>
using namespace std;

TaskList::TaskList()
{
    head = nullptr;
}

TaskList::~TaskList()
{
    TaskNode* currNode = head;
    TaskNode* prevNode = head;
    while(currNode != nullptr)
    {
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode;
    }
}

void TaskList::addTask(string name)
{

}

void TaskList::deleteTask(string name)
{

}

void TaskList::importTasks(ifstream& file)
{

}

void TaskList::exportTasks(ofstream& file)
{

}
