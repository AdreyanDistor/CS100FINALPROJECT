#include "../header/TaskList.h"

#include "time.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
using namespace std;
int main()
{
    // srand(time(NULL));
    vector<string> names = {"Task 1","Task 2","Task 3","Task 4","Task5"};
    vector<string> tag = {"Tag 1","Tag 2","Tag 3","Tag 4","Tag 5"};
    vector<string> desc = {"Description 1","Description 2","Description 3","Description 4","Description 5"};
    vector<int> year = {2001,2002,2003,2004,2005,};
    TaskList list;

    cout << "UNIT TESTS: " << endl;

    cout << "Adding two tasks" << endl << "BEFORE: ";
    list.printList();
    list.addTask(names.at(0),tag.at(0),desc.at(0), 5,5,2005);
    list.addTask(names.at(1),tag.at(0),desc.at(0), 5,3,2005);
    list.printList();
    cout << "Adding two tasks w/different years" << endl;
    TaskList list2;
    list2.printList();
    list2.addTask(names.at(0),tag.at(0),desc.at(0), 5,5,2005);
    list2.addTask(names.at(1),tag.at(0),desc.at(0), 5,3,2003);
    list2.printList();
    cout << "Adding two tasks with different months and days and the same year" << endl;
    TaskList list3;
    list3.printList();
    list3.addTask(names.at(0),tag.at(0),desc.at(0), 6,2,2005);
    list3.addTask(names.at(1),tag.at(0),desc.at(0), 5,3,2005);
    list3.printList();
    cout << "Adding two tasks where only the day is different" << endl;
    TaskList list4;
    list4.printList();
    list4.addTask(names.at(0),tag.at(0),desc.at(2), 5,2,2005);
    list4.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);
    list4.printList();
    cout << "Adding multiple tasks w/different years" << endl;
    TaskList list5;
    list5.printList();
    list5.addTask(names.at(0),tag.at(0),desc.at(2), 5,2,2005);
    list5.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2003);
    list5.addTask(names.at(2),tag.at(0),desc.at(4), 5,3,2001);
    list5.printList();
    cout << "Adding multiple tasks w/months days and the same year" << endl;
    TaskList list6;
    list6.printList();
    list6.addTask(names.at(0),tag.at(0),desc.at(2), 2,2,2001);
    list6.addTask(names.at(1),tag.at(0),desc.at(3), 3,3,2001);
    list6.addTask(names.at(2),tag.at(0),desc.at(4), 4,5,2001);
    list6.printList();
    cout << "Adding multiple tasks where only the day is different" << endl;
    TaskList list7;
    list7.printList();
    list7.addTask(names.at(0),tag.at(0),desc.at(2), 5,2,2005);
    list7.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);
    list7.addTask(names.at(2),tag.at(0),desc.at(4), 5,24,2005);
    list7.printList();
    cout << "Deleting head" << endl;
    TaskList list8;
    list8.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);    
    list8.printList();
    list8.deleteTask(names.at(1));
    list8.printList();
    cout <<"Deleting tail" << endl;
    TaskList list9;
    list9.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);    
    list9.addTask(names.at(0),tag.at(0),desc.at(3), 5,6,2005);    
    list9.printList();
    list9.deleteTask(names.at(0));
    list9.printList();
    cout << "Deleting head and tail" << endl;
    list9.deleteTask(names.at(0));
    list9.deleteTask(names.at(1));
    list.printList();
    cout << "Deleting in the middle of the list" << endl;
    TaskList list10;
    list10.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);    
    list10.addTask(names.at(0),tag.at(0),desc.at(3), 5,6,2005);  
        list10.addTask(names.at(2),tag.at(0),desc.at(3), 5,7,2005);    
  
    list10.printList();
    list10.deleteTask(names.at(0));
    list10.printList();



    return 0;
}

