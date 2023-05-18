#include "TaskList.h"
#include <iostream>
#include <fstream>
using namespace std;

int TaskList::getTotalPoints() const {
    return totalPoints;
}

void TaskList::markTaskCompleted(string name) {
    TaskNode* curr = head;
    string wholeTask;
    ifstream inFS;
    int count = 1;
    inFS.open("Tasklist.txt");
    if(!inFS.is_open()) {
        cout << "error opening file" << endl;
        return;
    }
    while (curr != nullptr || curr->title != name) { //finding the task in question 
        curr = curr->next;
        count++;
    }
    if (curr == nullptr) {
        cout << "task does not exist try again." << endl; //FIX - give an error or something 
    }
    curr->done = true; 
    // for (int i = 0; i < count; i++) {
    //     getline(inFS, wholeTask);
    // }
    totalPoints += curr->value;
    deleteTask(name);
}