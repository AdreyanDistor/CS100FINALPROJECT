#include "../header/AwardListGUI.h"

 AwardListGUI::AwardListGUI()
 {
        awardlistSize = 0;
 }

void AwardListGUI::displayAwards()
{
    cout << "      Count-Price-Name" << endl;
    for(int i = 0; i <awardlist.size(); i++)
    {
        cout << i + 1 << ".     ";
        awardlist.at(i)->displayAward();
        cout << endl;
    }
}
