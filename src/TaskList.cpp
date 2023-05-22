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
        TaskNode* tempNode = nullptr;
        tempNode = currNode;
        currNode = currNode->next;
        delete tempNode;
    }
    
}

void TaskList::addTask(string name, string tag,string description, int day, int month, int time)
{
    TaskNode* newNode = new TaskNode(name, tag,description, day, month,time);
    if(head == nullptr)
    {
        head = newNode;
    }
    else if(tail == nullptr)
    {
        tail = newNode;
        head->next = tail;
    }
    else
    {
        TaskNode* tempNode = tail;
        tail = newNode;
        tempNode->next = tail;
    }
}

//this needs to be debugged
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
        prevNode = currNode;
        currNode = currNode->next;
    }
}

void TaskList::sortByTag(string user_tag)
{
    TaskNode* currNode = head;
    if(currNode != nullptr)
    {
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
    }
    
   
    return;
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
    }
    
}