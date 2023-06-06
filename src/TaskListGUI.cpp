#include "../header/TaskListGUI.h"

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
string TaskListGUI::showOverdue()
{
    string overdueList = "";
    TaskNode* currNode = head;
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
