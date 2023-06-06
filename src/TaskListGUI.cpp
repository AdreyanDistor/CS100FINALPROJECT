#include "../header/TaskListGUI.h"
using namespace std;

TaskListGUI::TaskListGUI()
{
    head = nullptr;
    recent_deleted_Task = nullptr;
    tail = nullptr;
}

void TaskListGUI::showOverdue(char* tm) {
    TaskNode* curr = head;
    string time = tm;
    string monthStr = time.substr(4, 3);
    int currDay = stoi(time.substr(8, 2));
    int currMonth = 0;
    int currYear = stoi(time.substr(20, 4));
    
    if (monthStr == "Jan") {
        currMonth = 1;
    } else if (monthStr == "Feb") {
        currMonth = 2;
    } else if (monthStr == "Mar") {
        currMonth = 3;
    } else if (monthStr == "Apr") {
        currMonth = 4;
    } else if (monthStr == "May") {
        currMonth = 5;
    } else if (monthStr == "Jun") {
        currMonth = 6;
    } else if (monthStr == "Jul") {
        currMonth = 7;
    } else if (monthStr == "Aug") {
        currMonth = 8;
    } else if (monthStr == "Sep") {
        currMonth = 9;
    } else if (monthStr == "Oct") {
        currMonth = 10;
    } else if (monthStr == "Nov") {
        currMonth = 11;
    } else if (monthStr == "Dec") {
        currMonth = 12;
    }

    while (curr != nullptr) {
        if (curr->year > currYear) {
            curr->overdue = true;
        } else if (curr->month > currMonth) {
            curr->overdue = true;
        } else if (curr->day > currDay) {
            curr->overdue = true;
        }
        curr = curr->next;
    }
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
void TaskListGUI::printList()
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
