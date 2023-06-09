#ifndef AWARDLISTGUI_H
#define AWARDLISTGUI_H
#include "AwardList.h"
#include <iostream>
#include <ostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class AwardListGUI: public AwardList{
    public:
        void displayAwards(); //showing the awards on GUI
        void displayPointLog();
        AwardListGUI();
        
};

#endif 