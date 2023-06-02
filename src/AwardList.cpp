
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
    awardlistSize = 0;  // vector index

    // iterates through file to find each parameter in each TaskNode
    while (getline(input, award_name, '`')) {
        getline(input, cost, '`');
        getline(input, user_count);
        
        awardlist.at(awardlistSize) = new Award(award_name, stoi(cost), stoi(user_count));
        awardlistSize++;
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

    for (int i = 0; i < awardlistSize; i++) {
        output << awardlist.at(i)->exportAward() << endl;
    }

    remove("AwardList.txt");
    rename("temp.txt", "AwardList.txt");
    output.close();
}

