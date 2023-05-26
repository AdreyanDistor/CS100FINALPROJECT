#include "../header/AwardList.h"

AwardList::AwardList()
{
    
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

