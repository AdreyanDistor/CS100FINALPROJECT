#include "../header/TaskListGUI.h"

string TaskListGUI::showOverdue(TaskList list)
{
    string overdueList = "";
    TaskNode* currNode = list.head;
    while(currNode != nullptr)
    {
        if(currNode->overdue)
        {
            overdueList+=currNode->exportTask() + "\n";
        }
        currNode = currNode->next;
    }
    return overdueList;
}
string TaskListGUI::showTodayOnly(TaskList list,int day, int month, int year)
{
    string todayList = "";
    TaskNode* currNode = list.head;
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
string TaskListGUI::sortByTag(TaskList list, string user_tag)
{
    string tagList = "";
    TaskNode* currNode = list.head;
    while(currNode != nullptr)
    {
        if(currNode->tag == user_tag)
        {
            tagList+=currNode->exportTask() + "\n";
        }
        currNode = currNode->next;
    }
    return tagList;
}