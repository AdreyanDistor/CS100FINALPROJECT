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

class AwardListGUI: public AwardList{
    public:
        string displayAwards(); //showing the awards on GUI
};

#endif 