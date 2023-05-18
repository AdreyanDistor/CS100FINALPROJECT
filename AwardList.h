#ifndef AWARDLIST_H
#define AWARDLIST_H

#include <iostream>
#include <vector>
using namespace std;

struct Award {
        string title;
        int cost;
        int count;
        string image;
        Award(string name, int price) : title(name), cost(price), count(1) {}
        string exportAward();
};

class AwardList
{
        public:
                AwardList();
                void addAward();
                void deleteAward(string name);
                void importAwards(ifstream& file);
                void exportAwards(ofstream& file);
        private:
                vector<Award> awards;
};

#endif