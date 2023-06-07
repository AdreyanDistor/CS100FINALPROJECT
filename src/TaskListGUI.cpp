#include "../header/TaskListGUI.h"
using namespace std;

TaskListGUI::TaskListGUI()
{
    head = nullptr;
    recent_deleted_Task = nullptr;
    tail = nullptr;
}

void TaskListGUI::showOverdue(char* tm) {
    //display 
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

string TaskListGUI::printList()
{
    cout << "       Date      -       Tag       -       Name" << endl;
    TaskNode* currNode = head;
    string list = "";
    if(head == nullptr)
    {
        return list;
    }
    while (currNode !=nullptr)
    {
        list+= i + ". " + currNode->exportTask() + "\n";
        currNode = currNode->next; 
        i++;
    }
    return list;
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


