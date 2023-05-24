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


int TaskList::markTaskCompleted(string name) {
    TaskNode* curr = head;
    while (curr->name != name) { //finding the task in question 
        curr = curr->next;
    }
    if (curr->tag == "chore") {
        return 5;
    } else if (curr->tag == "essay") {
        return 10;
    } else if (curr->tag == "short_assign") {
        return 7;
    } else if (curr->tag == "long_assign") {
        return 12;
    } else if (curr->tag == "studying") {
        return 7;
    } else if (curr->tag == "project") {
        return 20;
    } else if (curr->tag == "other") {
        return 0;
    } else if (curr->tag == "lab") {
        return 7;
    }
    deleteTask(name);
    return -1;
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

