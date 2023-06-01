#include "../header/AwardListGUI.h"

string AwardListGUI::displayAwards(AwardList list)
{
    string AWARDS;
    for(int i = 0; i < list.awardlist.size(); i++)
    {
        AWARDS+=list.awardlist.at(i)->exportAward();
    }
    return AWARDS;
}