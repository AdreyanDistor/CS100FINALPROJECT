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
    if(head == tail)
    {
        delete head;
    }
    else
    {
        while(currNode != nullptr)
        {
            TaskNode* tempNode;
            tempNode = currNode;
            currNode = currNode->next;
            delete tempNode;
        }
    }
    
}

void TaskList::addTask(string name, string tag,string description, int day, int month, int time)
{
    TaskNode* newNode = new TaskNode(name, tag,description,day, month,time);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        head->next = tail;
    }
    if(tail == nullptr)
    {
        head->next = tail;
        tail = newNode;
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
    TaskNode* prevNode = head;
    while(currNode != nullptr)
    {
        if(currNode->name == name)
        {
            if(currNode == head)
            {
                head = head->next;
                tail = nullptr;
                
            }
            else if(currNode == tail)
            {
                tail = prevNode;
                head->next = tail;
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
    if(head == tail)
    {
        if(currNode->tag == user_tag)
        {
            cout << currNode->exportTask() << endl;
        }
    }
    else
    {
        while(currNode != nullptr)
        {
            if(currNode->tag == user_tag)
            {
                cout << currNode->exportTask() << endl;
            }
            currNode = currNode->next;
        }
    }
   
    return;
}