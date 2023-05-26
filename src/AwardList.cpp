#include "../header/AwardList.h"

AwardList::AwardList()
{
    
}

AwardList::buyAward(string buyingAward, int totalPoints) {
    unsigned i = 0;
    while(awardlist.at(i).award_name != buyingAward && i < awardlist.size()) { //find specified award in the vector
        ++i;
    }

    if(totalPoints >= awardlist.at(i).cost) { 
        totalPoints -= awardlist.at(i).cost;
        awardlist.at(i).user_count++;
    }
    return;
}


