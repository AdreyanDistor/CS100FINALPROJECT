#include "../header/TaskList.h"

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
        TaskNode* tempNode;
        tempNode = currNode;
        currNode = currNode->next;
        delete tempNode;
    }
}

void TaskList::addTask(string name, string tag,string description, int day, int month, int time)
{
    TaskNode* newNode = new TaskNode(name, tag,description,day, month,time);
    if(head == nullptr)
    {
        head = newNode;
        tail = nullptr;
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
        if(currNode->name == name)
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