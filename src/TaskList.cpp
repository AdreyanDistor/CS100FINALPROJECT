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

void TaskList::addTask(string name, string tag,string description, int day, int month, int year)
{
    TaskNode* newNode = new TaskNode(name, tag,description, day, month,year);
    if(head == nullptr)
    {
        head = newNode;
    }
    else if(tail == nullptr)
    {
        tail = newNode;
        head->next = tail;
        bool tailEarlier = false;
        TaskNode* tempNode = head;
       
        if(tail->year < head->year)
        {
            tailEarlier = true;
        }
        else if(tail->year == head->year)
        {
            if(tail->month < head->month)
            {
                tailEarlier == true;
            }
            else if(tail->month == head->month)
            {
                if(tail->day <= head->day)
                {
                    tailEarlier == true;
                }
            }
        }

        if(tailEarlier)
        {
            head = tail;
            tail = tempNode;
            tail->next = nullptr;
            head->next = tail;
        }

    }
    else
    {
        
            TaskNode* currNode = head;
            TaskNode* prevNode = head;
            while(currNode != nullptr)
            {
                bool newNodeEarlier = false;
                if(newNode->year < currNode->year)
                {
                    newNodeEarlier = true;
                }
                else if(newNode->year == currNode->year)
                {
                    if(newNode->month < currNode->month)
                    {
                        newNodeEarlier = true;
                    }
                    else if(newNode->month == currNode->month)
                    {
                        if(newNode->day <= currNode->day)
                        {
                           newNodeEarlier == true;
                        }
                    }
                }

                if(newNodeEarlier)
                {
                    if(currNode == head)
                    {
                        newNode->next = head;
                        head = newNode;
                    }
                    else
                    {
                        prevNode->next = newNode;
                        newNode->next = currNode;
                    }
                    return;
                }
                prevNode = currNode;
                currNode = currNode->next;

            }

            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        
    }
    return;
}

void TaskList::deleteTask(string name)
{
    TaskNode* currNode = head;
    TaskNode* prevNode = head;
    while(currNode !=nullptr)
    {   
        if(currNode->name == name)
        {
            if(currNode == head)
            {
                TaskNode* tempNode = head;
                head = head->next;
                if(head == tail)
                {
                    tail == nullptr;
                }
            }
            else if(currNode == tail)
            {
                tail = prevNode;
                tail->next = nullptr;
            }
            else
            {
                prevNode->next = currNode->next;
            }
            delete currNode;
            return;
        }
                    recent_deleted_Task = new TaskNode(currNode->name, currNode->tag,currNode->description, currNode->day, currNode->month, currNode->year);
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// COULD ADD TO GUI CLASS
void TaskList::printList()
{
    int i = 1;
    TaskNode* currNode = head;
    if(head == nullptr)
    {
        cout << "" << endl;
    }
    while (currNode !=nullptr)
    {
        cout << i << ". " << currNode->exportTask() << endl;
        currNode = currNode->next; 
        i++;
    }
}
