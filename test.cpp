#include "header/TaskList.h"

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
    vector<int> year = {1,2,3,4,5,};
    TaskList list;
    for(int i = 0; i < 3; i++)
    {
        list.addTask(names.at(i),tag.at(i),desc.at(i),month.at(i),day.at(i),year.at(i));
    }
    cout << "BEFORE DELETE" << endl;
    list.printList();
    list.deleteTask("1");
    cout << "AFTER DELETE" << endl;
    list.printList();


    return 0;
}

