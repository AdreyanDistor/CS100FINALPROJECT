#ifndef TASKLIST_H
#define TASKLIST_H
#include <iostream>
#include <fstream>
#include <ostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include "AwardListGUI.h"
using namespace std;

struct TaskNode
{
	int day;
	int month;
    int year;
	string description;
	string name;
    string tag; //chore = 5, essay = 10, short_assign = 7, long_assign = 12, studying = 7, project = 20, other = 0, lab = 7
	bool overdue;
    TaskNode():name(""), tag(""), description(""), day(0), month(0),overdue(false),next(nullptr), year(0){}
    TaskNode(string name, string tag,string description, int day, int month, int year):
    name(name), tag(tag), description(description), day(day), month(month), year(year),overdue(false){}
	TaskNode* next;
    void setName(string newName) {
        name = newName;
    }

    void setDescription(string newDes) {
        description = newDes;
    }
    
    void setTag(string newTag) {
        if (newTag == " " || newTag == "") {
            tag = "other";
        } else {
            tag = newTag;
        }
    }

    void setMonth(int newMon) {
        if (newMon < 1) {
            month = 1;
        } else if (newMon > 12) {
            month = newMon % 12;
        } else {
            month = newMon;
        }
    }

    void setDay(int newDay) {
        if (newDay < 1) {
            day = 1;
        } else if (month == 2 && newDay > 28) {
            day = 28;
        } else if (newDay > 31) {
            day = 31;
        } else {
            day = newDay;
        }
    }
    
    void setYear(int newYear) {
        year = newYear;
    }

	string exportTask()
    {
        string output = name + '`' + tag + '`' + description +  '`' + to_string(day) + '`' + to_string(month) + '`' + to_string(year);
        return output;
    }; //this will be used in exportTasks of the Tasklist file

    string displayTask() {

        string x;
        string shortTag;
        string date;

        if (overdue) {
            x = "x    ";
        } else {
            x = "     ";
        }

        // abbreviates the tag
        if (tag == "chore") {
            shortTag = "CHORE";
        } else if (tag == "essay") {
            shortTag = "ESSAY";
        } else if (tag == "short_assign") {
            shortTag = "SHORT";
        } else if (tag == "long_assign") {
            shortTag = "LONG_";
        } else if (tag == "studying") {
            shortTag = "STUDY";
        } else if (tag == "project") {
            shortTag = "PROJT";
        } else if (tag == "lab") {
            shortTag = "LAB__";
        } else {
            shortTag = "OTHER";
        }

        string newYear = to_string(year%2000);
        string newDay = to_string(day);
        string newMonth = to_string(month);

        date = printDate();
        
        return x + "      " + date + "      " + shortTag + "      " + name;
    }

	string printDate() {
        ostringstream osS; 
        osS << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << year;
        return osS.str(); 
    }

  bool thisNodeEarlier(TaskNode* otherNode)
  {
    bool thisNodeEarly = false;
    if(year < otherNode->year)
    {
       return true;
    }
    else if(year == otherNode->year)
    {
        if(month < otherNode->month)
        {
            return true;
        }
        else if(month == otherNode->month)
        {
            if(day < otherNode->day)
            {
                return true;
            }
            else if(day == otherNode->day)
            {
                return false;
            }
        }
    }
    return false;
  }
};


class TaskList
{
    protected:
        TaskNode* head;
        TaskNode* tail;
        TaskNode* recent_deleted_Task;
    public:
        TaskList();
        ~TaskList();
        void addTask(string name, string tag,string description, int day, int month, int year);  //Make sure no duplicates
        void deleteTask(string name); // removes task from list, 
        void undoDeleteTask(); //adds task back into list, if unsorted, just at the end of the list. If recent_deleted_task is = “” then nothin happens
        TaskNode* search(string); //searches list until task with same name is found, returns nullptr otherwise	
        void importTasks(string filename); //import tasks from the file(name) parameter and forms a linked list
        void exportTasks(string filename); //will use the linked list and write to the file to save the user's data
        void markOverdue(); //marks tasks overdue by turning the isOverdue bool true 
        void markTaskCompleted(string name, AwardListGUI& awardList); //returns amount of points associated with the tag of the task.  calls delete Task  Will be used to add to global: total_points, 
        void editTask(string title); //edits a task
        void printEditMenu(); //helper func used in editTask();
};

	
#endif
