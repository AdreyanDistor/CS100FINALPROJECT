#ifndef TASKLIST_H
#define TASKLIST_H
#include <iostream>
#include <fstream>
#include<ostream>
#include <ctime>
#include<string>
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
	string exportTask()
    {
        string isOverdue;
        if(overdue == true)
        {
            isOverdue = "true";
        }
        else
        {
            isOverdue = "false";
        }
        string output = name + '`' + description + '`' + tag +  '`' + to_string(month) + '`' + to_string(day) + '`' + to_string(year) + '`' + isOverdue;
        return output;
    }; //this will be used in exportTasks of the Tasklist file

    // TEST THIS
    string displayTask() {

        string x;
        string shortTag;
        string date;

        if (overdue) {
            x = "x    ";
        } else {
            x = "      ";
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

        if (day < 10) {
            newDay = "0" + newDay;
        }
        if (month < 10) {
            newMonth = "0" + newMonth;
        }
        if (day < 10) {
            newMonth = "0" + newMonth;
        }

        date = to_string(day) + "." + to_string(month) + "." + to_string(year%2000);
        
        return x + "      " + date + "      " + shortTag + "      " + name;
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
        void update(); // updates time and overdue tasks, updates every hour? (I don’t remember exactly)
        void undoDeleteTask(); //adds task back into list, if unsorted, just at the end of the list. If recent_deleted_task is = “” then nothin happens
        TaskNode* search(string); //searches list until task with same name is found, returns nullptr otherwise	
        void importTasks(); //import tasks from “TaskList.txt”, look at TaskList to see how to import, makes the linked list 
        void exportTasks(); //will ouput and write the file the function named “TaskList.txt”
        void markTaskCompleted(string name,int& totalPoints); //returns amount of points associated with the tag of the task.  calls delete Task  Will be used to add to global: total_points,
        void markOverdue(char* tm); //marks tasks overdue by turning the isOverdue bool true 
};

	
#endif
