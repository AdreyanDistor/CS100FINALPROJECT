#include "../header/AwardListGUI.h"

 AwardListGUI::AwardListGUI()
 {}

void AwardListGUI::displayAwards()
{
    cout << "      Count-Price-Name" << endl;
    for(int i = 0; i <awardVector.size(); i++)
    {
        cout << i + 1 << ".     ";
        awardVector.at(i)->displayAward();
        cout << endl;
    }
    cout << "POINTS: " << totalPoints << endl;
}

void AwardListGUI::displayPointLog()
{
    ifstream pointLog;
    pointLog.open("saved_files/Point_Log.txt");
    while(!pointLog.eof())
    {
        string message;
        getline(pointLog,message);
        cout << message << endl;
    }
    pointLog.close();
}
