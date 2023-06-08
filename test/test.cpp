#include "../googletest/googletest/include/gtest/gtest.h"
#include "../header/AwardListGUI.h"
#include "../header/TaskListGUI.h"
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

TEST(addTask, onlyHead)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    EXPECT_TRUE(list.search("one") != nullptr);
}

TEST(addTask, onlyHeadandTail)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "chore", "second one", 1, 1, 2022);
    EXPECT_TRUE(list.search("two") != nullptr);
}

TEST(addTask, ThreeTasks)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 4, 2012);
    list.addTask("two", "chore", "second one", 1, 2, 2022);
    list.addTask("three", "chore", "third one", 1, 3, 2012);
    EXPECT_TRUE(list.search("three") != nullptr);
}

TEST(deleteTask, onlyHead)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.deleteTask("one");
    EXPECT_TRUE(list.search("one") == nullptr);
}

TEST(deleteTask, onlyHeadandTail)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "chore", "second one", 0, 2, 2022);
    list.deleteTask("one");
    list.deleteTask("two");
    EXPECT_TRUE(list.search("one") == nullptr);
    EXPECT_TRUE(list.search("two") == nullptr);
}

// TEST(deleteTask, ThreeTasks)
// {
//     TaskListGUI list;
//     list.addTask("one", "chore", "first one", 1, 4, 2012);
//     list.addTask("two", "chore", "second one", 1, 2, 2022);
//     list.addTask("three", "chore", "third one", 1, 4, 2012);
//     list.deleteTask("one");
//     list.deleteTask("two");
//     list.deleteTask("three");
//     EXPECT_TRUE(list.search("one") == nullptr);
//     EXPECT_TRUE(list.search("two") == nullptr);
//     EXPECT_TRUE(list.search("three") == nullptr);
// }

TEST(markTaskComplete, test) {
    TaskList list;
    int points = 0;
    list.addTask("one", "chore", "random", 5, 4, 2023);
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 5);
}

TEST(markTaskComplete, testtaskOverdue) {
    TaskListGUI list;
    int points = 0;
    list.addTask("one", "essay", "random", 5, 4, 2023);
    char* tm = "Fri Jul 3 00:00:00 2023";
    list.markOverdue(tm);
    list.showOverdue();
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 5); 
}

TEST(createAwardTest, testAwardSucessfullyCreated) {
    AwardList t1;
    t1.createAward("test award", 50);
    EXPECT_EQ(t1.getAwardVector().size(), 1);
    EXPECT_EQ(t1.getAwardVector().at(0)->award_name, "test award");
}

TEST(createAwardTest, testAwardPushBack) {
    AwardList t1;
    t1.createAward("test award", 50);
    t1.createAward("test award 2", 75);
    EXPECT_EQ(t1.getAwardVector().size(), 2);
    EXPECT_EQ(t1.getAwardVector().at(1)->award_name, "test award 2" );
}

TEST(deleteAwardTest, testAwardDeleted) {
    AwardList t1;
    t1.createAward("test award", 50);
    EXPECT_EQ(t1.getAwardVector().size(), 1);
    t1.deleteAward("test award");
    EXPECT_EQ(t1.getAwardVector().size(), 0);
}

TEST(deleteAwardTest, testCorrectAwardDeleted) {
    AwardList t1;
    t1.createAward("test award", 50);
    t1.createAward("test award 2", 75);
    t1.createAward("test award 3", 100);
    t1.deleteAward("test award");
    EXPECT_EQ(t1.getAwardVector().size(), 2);
    EXPECT_EQ(t1.getAwardVector().at(0)->award_name, "test award 2");
}

TEST(showOverDue, test) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "chore", "second one", 3, 6, 2023);
    list.addTask("three", "chore", "third one", 22, 11, 2023);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue(tm);
    list.showOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, true);
    EXPECT_EQ(curr2->overdue, true);
    EXPECT_EQ(curr3->overdue, false);
}


TEST(markComplete, pointLog)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    int points = 5;
    list.markTaskCompleted("one",points);
    EXPECT_EQ(points, 10);

}

TEST(buyAward, pointLog)
{
    AwardListGUI list;
    list.createAward("WOWOWOW",5);
    list.setTotalPoints(10);
    list.buyAward("WOWOWOW",1);
    list.useAward("WOWOWOW");
    EXPECT_EQ(5, list.getTotalPoints());
}

TEST(markOverDue, test) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "chore", "second one", 3, 6, 2023);
    list.addTask("three", "chore", "third one", 22, 11, 2023);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue(tm);
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, true);
    EXPECT_EQ(curr2->overdue, true);
    EXPECT_EQ(curr3->overdue, false);
} 

TEST(markTaskComplete, testTaskOverdue) {
    TaskListGUI list;
    int points = 0;
    list.addTask("one", "essay", "random", 5, 4, 2023);
    char* tm = "Fri Jul 3 00:00:00 2023";
    list.markOverdue(tm);
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 5); 
}

TEST(showOverdue, test) {
    TaskListGUI list;
    ostringstream osS;
    osS << "       Date      -       Tag       -       Name" << endl;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "essay", "second one", 3, 4, 2022);
    osS << list.search("one")->displayTask() << endl << list.search("two")->displayTask() << endl;
    char* time = "Fri Aug 15 00:00:00 2021";
    list.markOverdue(time);
    EXPECT_EQ(list.showOverdue(), osS.str());
}

TEST(editingATask, printDateFunc) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    EXPECT_EQ(curr->printDate(), "01/01/2022");
} 

TEST(editingATask, editTask) {
    TaskList list;
    list.addTask("one", "chore", "first one", 1, 2, 2022);
    list.addTask("two", "essay", "second one", 2, 3, 2023);
    string newDes = "changed";
    list.editTask("two");
    EXPECT_EQ(list.search("two")->description, "changed");
}

