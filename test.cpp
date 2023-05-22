#include "header/TaskList.h"
#include<iostream>
using namespace std;

int main()
{
    TaskList list;
    list.addTask("wow","chore","UHHUH",0,0,0);

    list.sortByTag("chore");
    return 0;
}
