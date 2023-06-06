#include "../header/AwardListGUI.h"

string AwardListGUI::displayAwards()
{
    string AWARDS;
    for(int i = 0; i <awardlist.size(); i++)
    {
        AWARDS+=awardlist.at(i)->exportAward();
    }
    return AWARDS;
}
