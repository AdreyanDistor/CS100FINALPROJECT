#include "../header/TaskList.h"
#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
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
    TaskNode* next = nullptr;
    while(currNode != nullptr)
    {
        next = currNode->next;
        delete currNode;
        currNode = next;
    }
    if(recent_deleted_Task != nullptr)
    {
        delete recent_deleted_Task;
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
        tail->next = nullptr;

        if(tail->thisNodeEarlier(head))
        {
            TaskNode* tempNode = head;
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
            if(newNode->thisNodeEarlier(currNode))
            {
                if(currNode == head)
                {
                    newNode->next = head;
                    head = newNode;
                }
                else if(currNode == tail)
                {
                    prevNode->next = newNode;
                    newNode->next = tail;
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
            recent_deleted_Task = new TaskNode(currNode->name, currNode->tag,currNode->description, currNode->day, currNode->month, currNode->year);
            delete currNode;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

TaskNode* TaskList::search(string name) {
    TaskNode* curr = head;
    while (curr != nullptr && curr->name != name) {
        curr = curr->next;
    }
    return curr;
}

void TaskList::markTaskCompleted(string name, AwardListGUI& awardList) {
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
        awardList.setTotalPoints(awardList.getTotalPoints() + point);
    } else {
        awardList.setTotalPoints(awardList.getTotalPoints() + (point/2));
    }
    
    this->deleteTask(name);
    string congratsMsg;
    string randomMsgs[4] = {"That's a job well done.","Good Job!","Congrats!","Cheers on finishing the task!"};
    srand(time(NULL));
    congratsMsg = randomMsgs[(rand() % 4)] + " You just completed: " + name + " and got " + to_string(point) + " points";
    cout << congratsMsg << endl;
    ofstream pointLog;
    pointLog.open("saved_files/Point_Log.txt",ios::app);

    if(pointLog.is_open())
    {
        pointLog << congratsMsg << endl;
    }
    else
    {
        cout << "WOW THAT DID NOT WORK" << endl;
    }
    pointLog.close();
}

void TaskList::importTasks(string filename) {
    ifstream input;
    input.open(filename);
    if (!input.is_open()) {
        cout << "Failed to open " + filename << endl;
        return;
    }

    string name;
    string tag;
    string description;
    string day; // to convert to int
    string month; // to convert to int 
    string year; // to convert to int
    // // iterates through file to find each parameter in each TaskNode
    while (getline(input, name, '`')) {
        getline(input, tag, '`');
        getline(input, description, '`');
        getline(input, day, '`');
        getline(input, month, '`');
        getline(input, year);

        addTask(name, tag, description, stoi(day), stoi(month), stoi(year));
    }
    markOverdue();

    input.close();

}

void TaskList::exportTasks(string filename) {

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

    const char* newFileName = filename.c_str();

    remove(newFileName);
    rename("temp.txt", newFileName);
    output.close();

}

void TaskList::markOverdue() {
    TaskNode* curr = head;
    time_t currentTime = time(0);
    struct tm* timeInfo = localtime(&currentTime);
    int currYear = timeInfo->tm_year + 1900;
    int currMonth = timeInfo->tm_mon + 1; 
    int currDay = timeInfo->tm_mday;
    while (curr != nullptr) {
        if (curr->year < currYear) 
        {
            curr->overdue = true;
        } 
        else if(curr->year == currYear)
        {
            if (curr->month < currMonth) 
            {
                curr->overdue = true;
            } 
            else if(curr->year == currYear)
            {
                if (curr->day < currDay) 
                {
                    curr->overdue = true;
                }
            }
        }
        
        curr = curr->next;
    }
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
    cout << "EditTask Page" << endl << endl;
    int option;
    printEditMenu();
    cin >> option;
    if(curr == nullptr)
    {
        return;
    }
    while (option != 5) {
        if (option == 1) { //name
            string _name;
            cout << "Enter new task name: " << endl;
            cin.ignore();
            getline(cin, _name);
            curr->setName(_name);
        } else if (option == 2) { //tag
            int _option;
            cout << "Tag options" << endl;
            cout << "1- chore | 2- essay | 3- short assignment | 4- long assignment" << endl;
            cout << "5- studying | 6- project | 7- lab | 8- other" << endl << endl;
            cout << "Enter option: " << endl;
            cin >> _option;

            if (_option == 1) {
                curr->setTag("chore");
            } else if (_option == 2) {
                curr->setTag("essay");
            } else if (_option == 3) {
                curr->setTag("short");
            } else if (_option == 4) {
                curr->setTag("long");
            } else if (_option == 5) {
                curr->setTag("study");
            } else if (_option == 6) {
                curr->setTag("proj");
            } else if (_option == 7) {
                curr->setTag("lab");
            } else if (_option == 8) {
                curr->setTag("other");
            }

        } else if (option == 3) { //description
            string _des;
            cout << "Enter new description: " << endl;
            cin.ignore();
            getline(cin, _des);
            curr->setDescription(_des);
        } else if (option == 4) { //date 
            int _option;
            cout << "Current Date: " << curr->printDate() << endl;
            cout << "What would you like to change?" << endl;
            cout << "1- Month | 2- Day | 3- Year | 4- Exit" << endl;
            cout << "Enter option: " << endl;
            cin >> _option;

            while (_option != 4) {
                if (_option == 1) {
                    int _month;
                    cout << "Enter new month: " << endl;
                    cin >> _month;
                    curr->setMonth(_month);
                } else if (_option == 2) {
                    int _day;
                    cout << "Enter new day: " << endl;
                    cin >> _day;
                    curr->setDay(_day);
                } else if (_option == 3) {
                    int _year;
                    cout << "Enter new year (YYYY): " << endl;
                    cin >> _year;
                    curr->setYear(_year);
                }
                cout << "Current Date: " << curr->printDate() << endl;
                cout << "What would you like to change?" << endl;
                cout << "1- Month | 2- Day | 3- Year | 4- Exit" << endl;
                cout << "Enter option: " << endl;
                cin >> _option;
            }

            TaskNode* newNode = new TaskNode(curr->name, curr->tag, curr->description, curr->day, curr->month, curr->year);
            deleteTask(curr->name);
            addTask(newNode->name, newNode->tag, newNode->description, newNode->day, newNode->month, newNode->year);
            curr = search(newNode->name);
        }

        printEditMenu();
        cin >> option;
    }
}

void TaskList::undoDeleteTask()
{
    if(recent_deleted_Task != nullptr)
    {
        addTask(recent_deleted_Task->name,recent_deleted_Task->tag,recent_deleted_Task->description,recent_deleted_Task->day,recent_deleted_Task->month,recent_deleted_Task->year);
        recent_deleted_Task = nullptr;
    }
    
}
