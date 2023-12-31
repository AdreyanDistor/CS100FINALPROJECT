#include "../header/AwardList.h"

AwardList::AwardList()
{
    totalPoints = 0;
}

AwardList::~AwardList() {
    while(!awardVector.empty())
    {
        Award* tempNode = awardVector.back();
        awardVector.pop_back();
        delete tempNode;
    }
}

void AwardList::importAwards(string filename) {
    ifstream input;
    input.open(filename);
    if (!input.is_open()) {
        cout << "Failed to open "+ filename << endl;
        return;
    }
  
    string cost; // to convert to int
    string user_count; // to convert to int
    string award_name;

    // iterates through file to find each parameter in each TaskNode
    while (getline(input, award_name, '`')) {
        getline(input, cost, '`');
        getline(input, user_count);
        awardVector.push_back(new Award(award_name, stoi(cost), stoi(user_count) ) );
    } 
    input.close();
} 
  
void AwardList::exportAwards(string filename) {
    // creating a file to replace AwardList.cpp
    ofstream output;
    output.open("temp.txt");
        if (!output.is_open()) {
        cout << "Failed to open temp.txt" << endl;
        return;
    }

    for (int i = 0; i < awardVector.size(); i++) {
        output << awardVector.at(i)->exportAward() << endl;
    }

    const char* newFileName = filename.c_str();

    remove(newFileName);
    rename("temp.txt", newFileName);
    output.close();
}

void AwardList::buyAward(string buyingAward, int quantity) {
    for(int i = 0; i < awardVector.size(); ++i) {
        if(awardVector.at(i)->award_name == buyingAward) {
            if(totalPoints >= (awardVector.at(i)->cost * quantity) ) {
                totalPoints -= awardVector.at(i)->cost * quantity;
                awardVector.at(i)->user_count += quantity;
                //pointLog
                ofstream pointLog;
                pointLog.open("saved_files/Point_Log.txt",ios::app);

                if(pointLog.is_open())
                {
                    pointLog << congratsMessage(awardVector.at(i), quantity) << endl;
                }
                else
                {
                    cout << "Error: cannot open Point_Log.txt" << endl;
                }
                pointLog.close();
            }
            else
            {
                cout << "Error: not enough points!" << endl;
            }
            return;
        }
    }
    cout << "Error: Award not found!" << endl;
}

string AwardList::congratsMessage(const Award* boughtAward, const int quantity) { 
    string congratsMsg;
    string randomMsgs[4] = {"Nice catch there bob!","Good eye their chief","Congrats!","That's a nice treat!"};
    srand(time(NULL));
    congratsMsg = randomMsgs[(rand() % 4)] + " You just bought: " + to_string(quantity) + " " + boughtAward->award_name + " and spent " +  to_string(boughtAward->cost*quantity) + " points";
    return congratsMsg;
}

void AwardList::useAward(string name) {
    for(int i = 0; i < awardVector.size(); ++i) {
        if(name == awardVector.at(i)->award_name)
        {
            if(awardVector.at(i)->user_count > 0)
                awardVector.at(i)->user_count--;
            else
                cout << "Error: not enough of award" << endl;
        }
            
        else
        {
            cout << "Error: Award not present" << endl;       
        }  
    }
}

void AwardList::createAward(string name, int cost) {
    // add an award to the end of the list with a count of zero
    for(int i = 0; i < awardVector.size(); i++) {
        if(awardVector.at(i)->award_name == name) {
            cout << "Award Already exists!" << endl;
            return;
        }
    }
    awardVector.push_back(new Award(name, cost, 0));

} 

void AwardList::deleteAward(string name) {
    // index of the award we are trying to delete
    int index = -1;

    // find the index of the award we are trying to delete
    for (int i = 0; i < awardVector.size(); i++) {
        if (awardVector.at(i)->award_name == name) {
            index = i;
            break;
        }
    }

    // if the award is found, hold that award in a temp value to delete later
    if (index != -1) {
        Award* temp = awardVector.at(index); 
        awardVector.erase(awardVector.begin()+index);
        delete temp; 
        temp = nullptr;
    }
}

int AwardList::getTotalPoints() {return totalPoints;}
void AwardList::setTotalPoints(int newTotalPoints) {totalPoints = newTotalPoints;}

//for testing
vector<Award*> AwardList::getAwardVector() { return awardVector; }

void AwardList::importTotalPoints()
{
    ifstream points;
    points.open("saved_files/Total_Points.txt");
    points >> totalPoints;
    points.close();
}

void AwardList::exportTotalPoints()
{
    ofstream points;
    points.open("saved_files/Total_Points.txt");
    points << totalPoints;
    points.close();
}
