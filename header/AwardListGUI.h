#ifndef AWARDLISTGUI_H
#define AWARDLISTGUI_H
#include "AwardList.h"
#include <iostream>
#include <ostream>
#include<fstream>
#include<vector>
#include<string>
#include "AwardList.h"
using namespace std;

class AwardListGUI{
    public:
        string displayAwards(AwardList list); //showing the awards on GUI
};

#endif 