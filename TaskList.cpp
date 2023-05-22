#include "TaskList.h"
#include <iostream>
using namespace std;

TaskList::TaskList()
{
    head = nullptr;
    tail = nullptr;
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

void TaskList::addTask(string name, int d, int m, int y, string des, string tag, int dueTime)
{
        cout << "addTag" << endl;

    TaskNode* newNode = new TaskNode(name,d,m,y,des,tag,dueTime);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        head->next = tail;
    }
    else
    {
        TaskNode* tempNode = tail;
        tail = newNode;
        tempNode->next = tail;
    }
    return;
}

//this needs to be debugged
void TaskList::deleteTask(string name)
{
    TaskNode* currNode = head;
    TaskNode* prevNode = nullptr;
    while(currNode != nullptr)
    {
        if(currNode->title == name)
        {
            if(currNode == head)
            {
                head = head->next;
                
            }
            else if(currNode == tail)
            {
                tail = prevNode;
            }
            else
            {
                prevNode->next = currNode->next;
            }
            delete currNode;
            currNode = nullptr;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

void TaskList::sortByTag(string user_tag)
{
    TaskNode* currNode = head;
    cout << "showTag" << endl;
    while(currNode != nullptr)
    {
        if(currNode->tag == user_tag)
        {
            cout << "EXPORT TASK" << endl;
            cout << currNode->exportTask() << endl;
        }
        currNode = currNode->next;
    }
    cout << "END SHOW TAG" << endl;
    return;
}

void TaskList::importTasks(ifstream& file)
{

}

void TaskList::exportTasks(ofstream& file)
{

}
