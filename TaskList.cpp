#include "TaskList.h"
#include <iostream>
using namespace std;

int TaskList::getTotalPoints() const {
    return totalPoints;
}

void TaskList::markTaskCompleted(string name) {
    TaskNode* curr = head;
    while (curr != nullptr || curr->title != name) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        cout << "task does not exist try again." << endl; //FIX - give an error or something 
    }
    curr->done = true;
    totalPoints += curr->value;
}