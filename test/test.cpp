#include "googletest/googletest/include/gtest/gtest.h"
#include "../header/AwardList.h"
#include "../header/TaskList.h"
#include<iostream>
#include<fstream>
#include <ostream>
#include<string>
#include<iomanip>
#include<vector>
#include<time.h>
#include<ctime>
using namespace std;
int main() {
    return 0;
}

//TESTING: buyAward()
TEST(buyAwardTest, testAwardSuccessfullyBought) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.setTotalPoints(10);

    testAwardList.buyAward("cupcake"); //error in buyAward
    EXPECT_EQ(testAwardList.getTotalPoints(), 0);
    EXPECT_EQ(testAwardList.getUserCount(0), 1);
}

// TEST(buyAwardTest, testNotEnoughMoney) {
//     AwardList testAwardList;

// }

