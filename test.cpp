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
    for(int i = 0; i < 1; i++)
    {
        int num = rand() % 4 + 0;
        list.addTask(names.at(num),tag.at(num),desc.at(num),month.at(num),day.at(num),year.at(num));
    }
    cout << "BEFORE DELETE" << endl;
    list.printList();
    cout << "AFTER DELETE" << endl;

    return 0;
}

