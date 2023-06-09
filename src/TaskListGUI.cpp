#include "../header/TaskListGUI.h"
#include <string>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


void TaskListGUI::showOverdue() {
    TaskNode* curr = head;
    cout << "       Date      -       Tag       -       Name" << endl;
    if (curr == nullptr) {
        return;
    }
    while (curr != nullptr) {
        if (curr->overdue == true) {
           cout << curr->displayTask() << endl;
        }
        curr = curr->next;
    }

}

void TaskListGUI::showTodayOnly(int day, int month, int year)
{
    TaskNode* currNode = head;
    while(currNode != nullptr)
    {
        if(currNode->day == day && currNode->month == month && currNode->year == year)
        {
            cout << currNode->displayTask() << endl;
        }
        currNode = currNode->next;
    }
}

void TaskListGUI::showByTag(string user_tag)
{
    TaskNode* currNode = head;
    if(currNode != nullptr)
    {
        if(head == tail)
        {
            if(currNode->tag == user_tag)
            {
                cout << currNode->displayTask() << endl;
            }
        }
        else
        {
            while(currNode != nullptr)
            {
                if(currNode->tag == user_tag)
                {
                    cout << currNode->displayTask() << endl;
                }
                currNode = currNode->next;
            }
        }
    }
    
}

void TaskListGUI::printList()
{
    cout << "       Date      -       Tag       -       Name" << endl;
    TaskNode* currNode = head;
    if(head == nullptr)
    {
        return;
    }
    while (currNode !=nullptr)
    {
        cout << currNode->displayTask() << endl;
        currNode = currNode->next; 
    }
}


void TaskListGUI::printOverdueMessage()
{
    TaskNode* currNode = head;
    while(currNode != nullptr)
    {
        if(currNode->overdue == true)
        {
            cout << "YOU HAVE OVERDUE TASKS!!!!" << endl;
            return;
        }
    }
}


