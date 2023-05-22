#include "header/TaskList.h"
#include<iostream>
using namespace std;

int main()
{    cout << "LIST" << endl;

    TaskList list;
    list.addTask("wow","chore","UHHUH",0,0,0);

    list.addTask("whuh","chore","UHHUH",0,0,0);
    list.deleteTask("whuh");
    // list.addTask("whuhwssd","chore","UHHUH",0,0,0);
    list.sortByTag("chore");
    return 0;
}
