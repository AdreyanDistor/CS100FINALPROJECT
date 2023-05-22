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