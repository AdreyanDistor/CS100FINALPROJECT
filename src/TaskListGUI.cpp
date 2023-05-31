#include "../header/TaskListGUI.h"

void TaskListGUI::sortByTag(string user_tag)
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
