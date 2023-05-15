#ifndef AWARD_H
#define AWARD_H

#include <iostream>
using namespace std;

class Award {
    private:
        string title;
        int cost;
        int count;
    public:
        Award(string name, int price) : title(name), cost(price), count(0) {}
};

#endif