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

void AwardList::importAwards() {
    ifstream input;
    input.open("AwardList.txt");
    if (!input.is_open()) {
        cout << "Failed to open AwardList.txt" << endl;
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
  
void AwardList::exportAwards() {
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

    remove("AwardList.txt");
    rename("temp.txt", "AwardList.txt");
    output.close();
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

void AwardList::createAward(string name, int cost) {
    // add an award to the end of the list with a count of zero
    for(int i = 0; i < awardVector.size(); ++i) {
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
