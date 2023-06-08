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

TEST(PrintList, noOverDue) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 23, 11, 2023);
    list.addTask("two", "studying", "second one", 14, 11, 2023);
    list.addTask("three", "other", "third one", 22, 11, 2023);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue(tm);
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    bool curr1Bool;
    bool curr2Bool;
    bool curr3Bool;
    curr1Bool = (curr1->displayTask() == "      11/23/2023      CHORE      one");
    curr2Bool = (curr2->displayTask() == "      11/14/2023      STUDY      two");
    curr3Bool = (curr2->displayTask() == "      11/22/2023      OTHER      three");
    EXPECT_EQ(curr1Bool, true);
    EXPECT_EQ(curr2Bool, true);
    EXPECT_EQ(curr3Bool, true);
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

TEST(deleteTask, ThreeTasks)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 4, 2012);
    list.addTask("two", "chore", "second one", 1, 2, 2022);
    list.addTask("three", "chore", "third one", 1, 4, 2012);
    list.deleteTask("one");
    list.deleteTask("two");
    list.deleteTask("three");
    EXPECT_TRUE(list.search("one") == nullptr);
    EXPECT_TRUE(list.search("two") == nullptr);
    EXPECT_TRUE(list.search("three") == nullptr);
}

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
>>>>>>> master
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
    list.addTask("three", "chore", "third one", 22, 11, 2023); //ERROR RIGHT HERE 
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

TEST(editingATask, printDateFunc1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    EXPECT_EQ(curr->printDate(), "01/01/2022");
} 

TEST(editingATask, printDateFunc2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 12, 12, 2012);
    EXPECT_EQ(curr->printDate(), "12/12/2012");
} 

TEST(editingATask, printDateFunc3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 10, 11, 2022);
    EXPECT_EQ(curr->printDate(), "11/10/2022");
} 

TEST(editingATask, setName1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setName("changed");
    EXPECT_EQ(curr->name, "changed");
} 

TEST(editingATask, setName2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setName(" ");
    EXPECT_EQ(curr->name, " ");
} 

TEST(editingATask, setName3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setName("new one");
    EXPECT_EQ(curr->name, "new one");
} 

TEST(editingATask, setDescription1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setDescription("changed");
    EXPECT_EQ(curr->description, "changed");
} 

TEST(editingATask, setDescription2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setDescription(" ");
    EXPECT_EQ(curr->description, " ");
} 

TEST(editingATask, setDescription3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setDescription("new one");
    EXPECT_EQ(curr->description, "new one");
} 

TEST(editingATask, setTag1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setTag("essay");
    EXPECT_EQ(curr->tag, "essay");
} 

TEST(editingATask, setTag2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setTag("long");
    EXPECT_EQ(curr->tag, "long");
} 

TEST(editingATask, setTag3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setTag("");
    EXPECT_EQ (curr->tag, "other");
} 

TEST(editingATask, setMonth1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setMonth(0);
    EXPECT_EQ(curr->month, 1);
} 

TEST(editingATask, setMonth2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setMonth(3);
    EXPECT_EQ(curr->month, 3);
} 

TEST(editingATask, setMonth3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setMonth(15);
    EXPECT_EQ(curr->month, 3);
} 

TEST(editingATask, setDay1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setDay(0);
    EXPECT_EQ(curr->day, 1);
} 

TEST(editingATask, setDay2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setDay(23);
    EXPECT_EQ(curr->day, 23);
} 

TEST(editingATask, setDay3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setDay(32);
    EXPECT_EQ(curr->day, 31);
} 

TEST(editingATask, setYear1) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setYear(0000);
    EXPECT_EQ(curr->year, 0000);
} 

TEST(editingATask, setYear2) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setYear(3023);
    EXPECT_EQ(curr->year, 3023);
} 

TEST(editingATask, setYEar3) {
    TaskNode* curr = new TaskNode("one", "chore", "first one", 1, 1, 2022);
    curr->setYear(2022);
    EXPECT_EQ(curr->year, 2022);
} 

TEST(markComplete, pointLog)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    int points = 5;
    list.markTaskCompleted("one",points);
    EXPECT_EQ(points, 10);

}
