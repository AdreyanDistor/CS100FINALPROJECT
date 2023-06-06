#include "googletest/googletest/include/gtest/gtest.h"
#include "../header/AwardList.h"
#include "../header/TaskList.h"
<<<<<<< HEAD
#include "../googletest/googletest/include/gtest/gtest.h"
=======
#include "../header/TaskListGUI.h"
>>>>>>> cbe581a141d1c90b2be8e5fceb16d4e6df964a05
#include<iostream>
#include<fstream>
#include <ostream>
#include<string>
#include<iomanip>
#include<vector>
#include<ctime>
#include "time.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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

TEST(showOverDue, test) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "chore", "second one", 3, 6, 2023);
    list.addTask("three", "chore", "third one", 22, 11, 2023);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.showOverdue(tm);
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, true);
    EXPECT_EQ(curr2->overdue, true);
    EXPECT_EQ(curr3->overdue, false);
}
