#include "../header/AwardList.h"

AwardList::AwardList()
{
    awardlistSize = 0;
    
}

int AwardList::getAwardListSize() { return awardlistSize; }
vector<Award*> AwardList::getAwardList() { return awardlist; }

void AwardList::createAward(string name, int cost) {
    // add an award to the end of the list with a count of zero
    awardlist.push_back(new Award(name, cost, 0));
    awardlistSize++;
} 

void AwardList::deleteAward(string name) {
    // index of the award we are trying to delete
    int index = -1;

    // find the index of the award we are trying to delete
    for (int i = 0; i < awardlistSize; i++) {
        if (awardlist.at(i)->award_name == name) {
            index = i;
            break;
        }
    }

    // if the award is found, hold that award in a temp value to delete later
    if (index != -1) {
        Award* temp = awardlist.at(index); 
        awardlist.erase(awardlist.begin()+index);
        delete temp; 
        temp = nullptr;
        awardlistSize--;
    }


} 