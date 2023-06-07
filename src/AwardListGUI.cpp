#include "../header/AwardListGUI.h"

 AwardListGUI::AwardListGUI()
 {
 }

void AwardListGUI::displayAwards()
{
    cout << "      Count-Price-Name" << endl;
    for(int i = 0; i <awardVector.size(); i++)
    {
        cout << i + 1 << ".     ";
        awardVector.at(i)->displayAward();
        cout << endl;
    }
}
