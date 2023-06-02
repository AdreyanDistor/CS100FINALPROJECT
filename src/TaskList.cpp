#include "../header/TaskList.h"


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