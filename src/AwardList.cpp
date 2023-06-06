#include "../header/AwardList.h"

AwardList::AwardList()
{
    totalPoints = 0;
}

AwardList::~AwardList() {
    for(int i = awardVector.size() - 1; i >= 0; ++i) {
        delete awardVector.at(i);
    }
}

// Redundant 
void AwardList::createAward(string name, int cost) {
    if(this->inList(name)) {
        cout << "Award already exists!" << endl;
        return;
    }
    Award* newAward = new Award(name, cost, 0);
    awardVector.push_back(newAward);
}

void AwardList::deleteAward(string name){
    for(int i = 0; i < awardVector.size(); ++i ) {
        if(awardVector.at(i)->award_name == name)
        delete awardVector.at(i);
    }
}

void AwardList::buyAward(string buyingAward, int quantity) {
    for(int i = 0; i < awardVector.size(); ++i) {
        if(awardVector.at(i)->award_name == buyingAward) {
            if(totalPoints >= (awardVector.at(i)->cost * quantity) ) {
                totalPoints -= awardVector.at(i)->cost * quantity;
                awardVector.at(i)->user_count += quantity;
            }
            else
            cout << "Error: not enough points!" << endl;
            
            return;
        }
    }
    cout << "Error: Award not found!" << endl;
}


void AwardList::useAward(string name) {
    for(int i = 0; i < awardVector.size(); ++i) {
        if(name == awardVector.at(i)->award_name)
            awardVector.at(i)->user_count--;
        else 
        cout << "Error: Award not present" << endl;         
    }
}

//stub
bool AwardList::inList(string name) {
    return false;
}
