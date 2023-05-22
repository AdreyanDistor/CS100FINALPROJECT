#include "TaskList.h"
#include<iostream>
using namespace std;

int main()
{
    TaskList list;
    list.addTask("BOB",5,2,2004,"wowowo","chore",7);
    list.addTask("B",5,2,2004,"wowowo","chore",7);
    list.addTask("BB",5,2,2004,"wowowo","chore",7);
    list.addTask("BOsadasdasdasdsa",5,2,2004,"wowowo","chore",7);

    list.sortByTag("chore");
    return 0;
}
