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

void TaskListGUI::addTaskGUI()
{
    cout << "Enter Task Name: (ex: Lecture HomeWork)" << endl << endl;
    string taskName;
    getline(cin,taskName);
    cin.clear();
    cout << "Choose Tag:" << endl <<
    "1 - Chore" << endl <<
    "2 - Essay" << endl <<
    "3 - Short Assignment" << endl <<
    "4 - Long Assignment" << endl <<
    "5 - Studying" << endl <<
    "6 - Project" << endl <<
    "7 - Lab" << endl <<
    "8 - Other" << endl;
    string taskTag;
    cin >> taskTag;
    if(taskTag == "1")
    {
        taskTag = "chore";
    }
    else if(taskTag == "2")
    {
        taskTag = "essay";
    }
    else if(taskTag == "3")
    {
        taskTag = "short_assign";
    }
    else if(taskTag == "4")
    {
        taskTag = "long_assign";

    }
    else if(taskTag == "5")
    {
        taskTag = "studying";

    }
    else if(taskTag == "6")
    {
        taskTag = "project";
    }
    else if(taskTag == "7")
    {
        taskTag = "lab";
    }
    else
    {
        taskTag = "other";
    }
    cout << endl << "Enter Due Date - Month: (ex: 11)" << endl;
    int taskMonth;
    cin >> taskMonth;
    cout << endl << "Enter Due Date - Day: (ex: 23)" << endl;
    int taskDay;
    cin >> taskDay;
    cout << endl << "Enter Due Date - Year: (ex: 2023)" << endl;
    int taskYear;
    cin >> taskYear;
    cout << endl << "Enter Description: ";
    string taskDescription;
    getline(cin,taskDescription);
    cin.clear();
    addTask(taskName, taskTag, taskDescription,taskDay,taskMonth,taskYear);
}

void TaskListGUI::deleteTaskGUI()
{
    cout << "Which task would you like to delete?" << endl;
    string task_toDeleteName;
    getline(cin, task_toDeleteName);
    cin.clear();
    TaskNode* task_toDelete = search(task_toDeleteName);
    if(task_toDelete != nullptr)
    {
        deleteTask(task_toDeleteName);
    }
    else
    {
        cout << "Couldn't find it" << endl;
    }
}

