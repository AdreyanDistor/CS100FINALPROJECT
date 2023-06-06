#include "../header/TaskList.h"
#include <iostream>
#include <string>
using namespace std;

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

void TaskList::addTask(string name, string tag,string description, int day, int month, int year)
{
    TaskNode* newNode = new TaskNode(name, tag,description, day, month,year);
    if(head == nullptr)
    {
        head = newNode;
    }
    else if(tail == nullptr)
    {
        tail = newNode;
        head->next = tail;
        bool tailEarlier = false;
        TaskNode* tempNode = head;
       
        if(tail->year < head->year)
        {
            tailEarlier = true;
        }
        else if(tail->year == head->year)
        {
            if(tail->month < head->month)
            {
                tailEarlier == true;
            }
            else if(tail->month == head->month)
            {
                if(tail->day <= head->day)
                {
                    tailEarlier == true;
                }
            }
        }

        if(tailEarlier)
        {
            head = tail;
            tail = tempNode;
            tail->next = nullptr;
            head->next = tail;
        }

    }
    else
    {
        
            TaskNode* currNode = head;
            TaskNode* prevNode = head;
            while(currNode != nullptr)
            {
                bool newNodeEarlier = false;
                if(newNode->year < currNode->year)
                {
                    newNodeEarlier = true;
                }
                else if(newNode->year == currNode->year)
                {
                    if(newNode->month < currNode->month)
                    {
                        newNodeEarlier = true;
                    }
                    else if(newNode->month == currNode->month)
                    {
                        if(newNode->day <= currNode->day)
                        {
                           newNodeEarlier == true;
                        }
                    }
                }

                if(newNodeEarlier)
                {
                    if(currNode == head)
                    {
                        newNode->next = head;
                        head = newNode;
                    }
                    else
                    {
                        prevNode->next = newNode;
                        newNode->next = currNode;
                    }
                    return;
                }
                prevNode = currNode;
                currNode = currNode->next;

            }

            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        
    }
    return;
}

void TaskList::deleteTask(string name)
{
    TaskNode* currNode = head;
    TaskNode* prevNode = head;
    while(currNode !=nullptr)
    {   
        if(currNode->name == name)
        {
            if(currNode == head)
            {
                TaskNode* tempNode = head;
                head = head->next;
                if(head == tail)
                {
                    tail == nullptr;
                }
            }
            else if(currNode == tail)
            {
                tail = prevNode;
                tail->next = nullptr;
            }
            else
            {
                prevNode->next = currNode->next;
            }
            delete currNode;
            return;
        }
                    recent_deleted_Task = new TaskNode(currNode->name, currNode->tag,currNode->description, currNode->day, currNode->month, currNode->year);
        prevNode = currNode;
        currNode = currNode->next;
    }
}

TaskNode* TaskList::search(string name) {
    TaskNode* curr = head;
    while (curr->name != name) {
        curr = curr->next;
    }
    return curr;
}

// should not return a number
void TaskList::markTaskCompleted(string name, int& totalPoints) {
    TaskNode* curr = search(name);
    int point = 0;
    if (curr->tag == "chore") {
        point = 5;
    } else if (curr->tag == "essay") {
        point = 10;
    } else if (curr->tag == "short_assign") {
        point = 7;
    } else if (curr->tag == "long_assign") {
        point = 12;
    } else if (curr->tag == "studying") {
        point = 7;
    } else if (curr->tag == "project") {
        point = 20;
    } else if (curr->tag == "other") {
        point = 0;
    } else if (curr->tag == "lab") {
        point = 7;
    }
    if (curr->overdue == false) {
        totalPoints += point; 
    } else {
        totalPoints += point/2;
    }
    this->deleteTask(name);

}



void TaskList::importTasks() {
    ifstream input;
    input.open("TaskList.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskList.txt" << endl;
        return;
    }

    TaskNode* temp = head;
    TaskNode* prev = head;
    string name;
    string tag;
    string description;
    string day; // to convert to int
    string month; // to convert to int 
    string year; // to convert to int
    string overdue; 

    // iterates through file to find each parameter in each TaskNode
    while (!input.eof()) {
        getline(input, name, '`');
        getline(input, tag, '`');
        getline(input, description, '`');
        getline(input, day, '`');
        getline(input, month, '`');
        getline(input, year, '`');
        getline(input, overdue);

        // creates a new TaskNode and moves to the next one
        // stoi() is to convert the string to an int
        temp = new TaskNode(name, tag, description, stoi(day), stoi(month), stoi(year));
        if (overdue == "true")
            temp->overdue = true;
        else
            temp->overdue = false;

        prev = temp;
        temp = temp->next;
    }
    cout << "3" << endl;
    tail = prev;
    delete temp;
    input.close();

}

void TaskList::exportTasks() {

    // creating a file to replace TaskList.cpp
    ofstream output;
    output.open("temp.txt");
        if (!output.is_open()) {
        cout << "Failed to open temp.txt" << endl;
        return;
    }

    TaskNode* temp = head;
    while (temp != nullptr) {
        output << temp->exportTask() << endl;
        temp = temp->next;
    }

    remove("TaskList.txt");
    rename("temp.txt", "TaskList.txt");
    output.close();

}




