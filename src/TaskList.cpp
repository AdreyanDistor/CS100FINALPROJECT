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

void TaskList::showOverdue() {
    TaskNode* curr = head;
    int currDay = 0;
    int currMon = 0;
    int currYear = 0;
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