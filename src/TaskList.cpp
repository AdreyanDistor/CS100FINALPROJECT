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

void TaskList::printEditMenu() {
    cout << "EDIT A TASK" << endl << endl;
    
    cout << "What would you like to edit?" << endl;
    cout << "1 - Name" << endl;
    cout << "2 - Tag" << endl;
    cout << "3 - Description" << endl;
    cout << "4 - Date" << endl;
    cout << "5 - Exit editor" << endl << endl;

    cout << "Enter option: " << endl;
}
void TaskList::editTask(string title) {
    TaskNode* curr = search(title);
    int option;
    printEditMenu();
    cin >> option;
    while (option != 5) {
        if (option == 1) { //name 
            string _name;
            cout << "Enter new name: " << endl;
            getline(cin, _name);
            cin.ignore();
            curr->name = _name;
            cout << "Name is now:" << _name << end;
        } else if (option == 2) { //tag
            int _tag;
            cout << "1- chore, 2- essay, 3- short assignment, 4- long assigment" << endl;
            cout << "5- studying, 6- project, 7- lab, 8- other " << endl;
            cout << "Enter the coresponding number for the new tag: " << endl;
            cin >> _tag;
            if (_tag == 1) {
                curr->tag = "chore";
            } else if (_tag == 2) {
                curr->tag = "essay";
            } else if (_tag == 3) {
                curr->tag = "short";
            } else if (_tag == 4) {
                curr->tag = "long";
            } else if (_tag == 5) {
                curr->tag = "study";
            } else if (_tag == 6) {
                curr->tag = "proj";
            } else if (_tag == 7) {
                curr->tag = "lab";
            } else if (_tag == 8) {
                curr->tag = "other";
            } else {
                cout << "Error: invalid input. Please try again." << endl;
                break;
            }
        } else if(option == 3) { //description 
            string _des;
            cout << "Enter new description: " << endl;
            getline(cin, _des);
            cin.ignore();
            curr->description = _des;
        } else if (option == 4) { //date
            int _option = 1;
            while (_option != 4) {
                cout << "Current due date: " << curr->printDate() << endl << endl;
                cout << "What do you want to change? Enter a number from the following options: " << endl;
                cout << "1- month, 2- day, 3-year, 4- done: " << endl;
                cin >> _option;
                if (_option == 1) { //month
                    int _month;
                    count << "Enter new month number: " << endl;
                    curr->month = _month;
                } else if (_option == 2) { //day
                    int _day; 
                    count << "Enter new day: " << endl;
                    curr->day = _day;
                } else if (_option == 3) { //year
                    int _year;
                    count << "Enter new year (YYYY): " << endl;
                    curr->year = _year;
                }
            }
        }
    }
}