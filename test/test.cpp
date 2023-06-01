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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(createAwardTest, testAwardSucessfullyCreated) {
    TaskList t1;
    t1.createAward("test award", 50);
    EXPECT_EQ(awardlistSize, 1);
    EXPECT_EQ(t1.getAwardList.at(0)->award_name, "test award");
}

TEST(createAwardTest, testAwardPushBack) {
    TaskList t1;
    t1.createAward("test award", 50);
    t1.createAward("test award 2", 75);
    EXPECT_EQ(awardlistSize, 2);
    EXPECT_EQ(t1.getAwardList().at(1)->award_name, "test award 2" );
}

TEST(deleteAwardTest, testAwardDeleted) {
    TaskList t1;
    t1.createAward("test award", 50);
    EXPECT_EQ(awardlistSize, 1);
    t1.deleteAward("test award");
    EXPECT_EQ(awardlistSize, 0);
}

TEST(deleteAwardTest, testCorrectAwardDeleted) {
    TaskList t1;
    t1.createAward("test award", 50);
    t1.createAward("test award 2", 75);
    t1.createAward("test award 3", 100);
    t1.deleteAward("test award");
    EXPECT_EQ(awardlistSize, 2);
    EXPECT_EQ(t1.getAwardList.at(0)->award_name, "test award 2");
}


