#include "../header/TaskList.h"

#include "time.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
using namespace std;
int main()
{
    srand(time(NULL));
    vector<string> names = {"1","2","3","4","5"};
    vector<string> tag = {"1","2","3","4","5"};
    vector<string> desc = {"1","2","3","4","5"};
    vector<int> month = {1,2,3,4,5,};
    vector<int> day = {1,2,3,4,5,};
    vector<int> year = {2001,2002,2003,2004,2005,};
    TaskList list;
    for(int i = 0; i < 10; i++)
    {
        list.addTask(names.at(rand() % 4 + 0),tag.at(rand() % 4 + 0),desc.at(rand() % 4 + 0),rand() % 30 + 1,rand() % 12 + 1,year.at(rand() % 4 + 0));
    }
    cout << "BEFORE DELETE" << endl;
    list.printList();
    list.deleteTask("1");
    cout << "AFTER DELETE" << endl;
    list.printList();


    return 0;
}

