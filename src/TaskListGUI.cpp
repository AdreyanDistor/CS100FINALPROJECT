#include "../header/TaskListGUI.h"
#include <string>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string TaskListGUI::showOverdue() {
    TaskNode* curr = head;
    ostringstream osS; 
    osS << "       Date      -       Tag       -       Name" << endl;
    if (curr == nullptr) {
        return osS.str();
    }
    while (curr != nullptr) {
        if (curr->overdue == true) {
            osS << curr->displayTask << endl;
        }
        curr = curr->next;
    }

    return osS.str();
}

string TaskListGUI::showTodayOnly(int day, int month, int year)
{
    string todayList = "";
    TaskNode* currNode = head;
    while(currNode != nullptr)
    {
        if(currNode->day == day && currNode->month == month && currNode->year == year)
        {
            todayList+=currNode->exportTask() + "\n";
        }
        currNode = currNode->next;
    }
    return todayList;
}

string TaskListGUI::sortByTag(string user_tag)
{
    TaskNode* currNode = head;
    string sortedTags;
    if(currNode != nullptr)
    {
        if(head == tail)
        {
            if(currNode->tag == user_tag)
            {
                sortedTags+= currNode->exportTask() + "\n";
            }
        }
        else
        {
            while(currNode != nullptr)
            {
                if(currNode->tag == user_tag)
                {
                    sortedTags+= currNode->exportTask() + "\n";
                }
                currNode = currNode->next;
            }
        }
    }
    
    return sortedTags;
}

// TEST THIS
void TaskListGUI::printList()
{
    cout << "       Date      -       Tag       -       Name" << endl;
    TaskNode* currNode = head;
    if(head != nullptr) {
        while (currNode != nullptr) {
            cout << currNode->displayTask() << endl;
            currNode = currNode->next; 
        }
    }
    
}


