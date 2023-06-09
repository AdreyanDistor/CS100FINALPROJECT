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
    list.markOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    bool curr1Bool;
    bool curr2Bool;
    bool curr3Bool;

    curr1Bool = (curr1->displayTask() == "           11/23/23      CHORE      one");
    curr2Bool = (curr2->displayTask() == "           11/14/23      STUDY      two");
    curr3Bool = (curr3->displayTask() == "           11/22/23      OTHER      three");
    EXPECT_EQ(curr1Bool, true);
    EXPECT_EQ(curr2Bool, true);
    EXPECT_EQ(curr3Bool, true);
}

TEST(PrintList, alloverdue) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 23, 11, 2021);
    list.addTask("two", "studying", "second one", 14, 11, 2021);
    list.addTask("three", "other", "third one", 22, 11, 2021);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    bool curr1Bool;
    bool curr2Bool;
    bool curr3Bool;
    curr1Bool = (curr1->displayTask() == "x          11/23/21      CHORE      one");
    curr2Bool = (curr2->displayTask() == "x          11/14/21      STUDY      two");
    curr3Bool = (curr3->displayTask() == "x          11/22/21      OTHER      three");
    EXPECT_EQ(curr1Bool, true);
    EXPECT_EQ(curr2Bool, true);
    EXPECT_EQ(curr3Bool, true);
}

TEST(PrintList, someoverdue) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 23, 11, 2021);
    list.addTask("two", "studying", "second one", 14, 11, 2024);
    list.addTask("three", "other", "third one", 22, 11, 2021);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    bool curr1Bool;
    bool curr2Bool;
    bool curr3Bool;
    curr1Bool = (curr1->displayTask() == "x          11/23/21      CHORE      one");
    curr2Bool = (curr2->displayTask() == "           11/14/24      STUDY      two");
    curr3Bool = (curr3->displayTask() == "x          11/22/21      OTHER      three");
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

TEST(importTasks, multipleTaskFile) {
    TaskListGUI list;
    list.importTasks("test/TaskListTest1.txt");
    TaskNode* firstTask = list.search("First Task");
    ASSERT_FALSE(firstTask == nullptr);
    TaskNode* secondTask = firstTask->next;
    ASSERT_FALSE(secondTask == nullptr);
    TaskNode* thirdTask = secondTask->next;
    ASSERT_FALSE(thirdTask == nullptr);
    TaskNode* fourthTask = thirdTask->next;
    ASSERT_FALSE(fourthTask == nullptr);

    bool firstTaskBool = false;
    bool secondTaskBool = false;
    bool thirdTaskBool = false;
    bool fourthTaskBool = false;
    if (firstTask->name == "First Task" && firstTask->tag == "short_assign" && firstTask->description == "description"
    && firstTask->day == 24 && firstTask->month == 3 && firstTask->year == 2023 && firstTask->overdue == false) {
        firstTaskBool = true;
    }

    if (secondTask->name == "Second Task" && secondTask->tag == "studying" && secondTask->description == "description"
    && secondTask->day == 12 && secondTask->month == 4 && secondTask->year == 2023 && secondTask->overdue == false) {
        secondTaskBool = true;
    }


    if (thirdTask->name == "Third Task" && thirdTask->tag == "other" && thirdTask->description == "description"
    && thirdTask->day == 29 && thirdTask->month == 5 && thirdTask->year == 2023 && thirdTask->overdue == false) {
        thirdTaskBool = true;
    }
    
    if (fourthTask->name == "Fourth Task" && fourthTask->tag == "chore" && fourthTask->description == "description"
    && fourthTask->day == 1 && fourthTask->month == 8 && fourthTask->year == 2023 && fourthTask->overdue == false) {
        fourthTaskBool = true;
    }
    EXPECT_EQ(firstTaskBool, true);
    EXPECT_EQ(secondTaskBool, true);
    EXPECT_EQ(thirdTaskBool, true);
    EXPECT_EQ(fourthTaskBool, true);
 
}

TEST(importTasks, oneTaskFile) {
    TaskListGUI list;
    list.importTasks("test/TaskListTest2.txt");
    TaskNode* firstTask = list.search("First Task");
    ASSERT_FALSE(firstTask == nullptr);

    bool firstTaskBool = false;

    if (firstTask->name == "First Task" && firstTask->tag == "long_assign" && firstTask->description == "hello"
    && firstTask->day == 26 && firstTask->month == 2 && firstTask->year == 2024 && firstTask->overdue == false) {
        firstTaskBool = true;
    }
    EXPECT_EQ(firstTaskBool, true);
 
}

TEST(importTasks, emptyFile) {
    TaskListGUI list;
    list.importTasks("test/TaskListTest3.txt");
    TaskNode* firstTask = list.search("First Task");
    ASSERT_TRUE(firstTask == nullptr);
 
}

TEST(exportTasks, emptyList) {
    TaskListGUI list;
    list.exportTasks("test/TaskListTest3.txt");
    ifstream input;
    input.open("test/TaskListTest3.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskListTest3.txt" << endl;
        return;
    }

    string name;
    EXPECT_FALSE(getline(input, name, '`'));
    input.close();
}

TEST(exportTasks, oneTaskList) {
    TaskListGUI list;
    list.addTask("one", "long_assign", "the description", 14, 1, 2025);
    list.exportTasks("test/TaskListTest3.txt");
    ifstream input;
    input.open("test/TaskListTest3.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskListTest3.txt" << endl;
        return;
    }

    string name;
    string tag;
    string description;
    string day; 
    string month; 
    string year;
    string overdue; 

    EXPECT_TRUE(getline(input, name, '`'));
    EXPECT_TRUE(name == "one");
    EXPECT_TRUE(getline(input, tag, '`'));
    EXPECT_TRUE(tag == "long_assign");
    EXPECT_TRUE(getline(input, description, '`'));
    EXPECT_TRUE(description == "the description");
    EXPECT_TRUE(getline(input, day, '`'));
    EXPECT_TRUE(day == "14");
    EXPECT_TRUE(getline(input, month, '`'));
    EXPECT_TRUE(month == "1");
    EXPECT_TRUE(getline(input, year, '`'));
    EXPECT_TRUE(year == "2025");
    EXPECT_TRUE(getline(input, overdue));
    EXPECT_TRUE(overdue == "false");
    input.close();
}

TEST(exportTasks, multipleTaskList) {
    TaskListGUI list;
    list.addTask("one", "long_assign", "the description", 14, 1, 2023);
    list.addTask("two", "project", "the description", 4, 8, 2024);
    list.addTask("three", "lab", "the description", 19, 1, 2025);
    list.addTask("four", "other", "the description", 20, 3, 2026);
    list.exportTasks("test/TaskListTest3.txt");
    ifstream input;
    input.open("test/TaskListTest3.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskListTest3.txt" << endl;
        return;
    }

    string line1;
    string line2;
    string line3;
    string line4;

    EXPECT_TRUE(getline(input, line1));
    EXPECT_TRUE(line1 == "one`long_assign`the description`14`1`2023`false");
    EXPECT_TRUE(getline(input, line2));
    EXPECT_TRUE(line2 == "two`project`the description`4`8`2024`false");
    EXPECT_TRUE(getline(input, line3));
    EXPECT_TRUE(line3 == "three`lab`the description`19`1`2025`false");
    EXPECT_TRUE(getline(input, line4));
    EXPECT_TRUE(line4 == "four`other`the description`20`3`2026`false");
    input.close();
}

TEST(importAwards, multipleAwardFile) {
    AwardList list;
    list.importAwards("test/AwardListTest1.txt");
    ASSERT_FALSE(list.getAwardVector().at(0) == nullptr);
    ASSERT_FALSE(list.getAwardVector().at(1) == nullptr);
    ASSERT_FALSE(list.getAwardVector().at(2) == nullptr);
    ASSERT_FALSE(list.getAwardVector().at(3) == nullptr);

    bool firstAwardBool = false;
    bool secondAwardBool = false;
    bool thirdAwardBool = false;
    bool fourthAwardBool = false;
    if (list.getAwardVector().at(0)->award_name == "Award 1" && list.getAwardVector().at(0)->cost == 10 && list.getAwardVector().at(0)->user_count == 3){
        firstAwardBool = true;
    }

    if (list.getAwardVector().at(1)->award_name == "Award 2" && list.getAwardVector().at(1)->cost == 35 && list.getAwardVector().at(1)->user_count == 0){
        secondAwardBool = true;
    }
    if (list.getAwardVector().at(2)->award_name == "Award 3" && list.getAwardVector().at(2)->cost == 240 && list.getAwardVector().at(2)->user_count == 12){
        thirdAwardBool = true;
    }
    if (list.getAwardVector().at(3)->award_name == "Award 4" && list.getAwardVector().at(3)->cost == 23 && list.getAwardVector().at(3)->user_count == 4){
        fourthAwardBool = true;
    }
    EXPECT_EQ(firstAwardBool, true);
    EXPECT_EQ(secondAwardBool, true);
    EXPECT_EQ(thirdAwardBool, true);
    EXPECT_EQ(fourthAwardBool, true);
 
}

TEST(importAwards, oneAwardFile) {
    AwardList list;
    list.importAwards("test/AwardListTest2.txt");
    ASSERT_FALSE(list.getAwardVector().at(0) == nullptr);

    bool firstAwardBool = false;
    if (list.getAwardVector().at(0)->award_name == "Buy a Brownie" && list.getAwardVector().at(0)->cost == 60 && list.getAwardVector().at(0)->user_count == 4){
        firstAwardBool = true;
    }
    EXPECT_EQ(firstAwardBool, true);
 
}

TEST(importAwards, emptyFile) {
    AwardList list;
    list.importAwards("test/AwardListTest3.txt");
    ASSERT_TRUE(list.getAwardVector().size() == 0);
 
}

TEST(exportAwards, multipleAwardsVector) {
    AwardList list;
    list.createAward("test award 1", 50);
    list.createAward("test award 2", 32);
    list.createAward("test award 3", 120);
    list.createAward("test award 4", 0);
    list.exportAwards("test/AwardListTest3.txt");
    ifstream input;
    input.open("test/AwardListTest3.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskListTest3.txt" << endl;
        return;
    }

    string line1;
    string line2;
    string line3;
    string line4;
    getline(input, line1);
    getline(input, line2);
    getline(input, line3);
    getline(input, line4);
    
    EXPECT_EQ(line1, "test award 1`50`0");
    EXPECT_EQ(line2, "test award 2`32`0");
    EXPECT_EQ(line3, "test award 3`120`0");
    EXPECT_EQ(line4, "test award 4`0`0");
    input.close();
}

TEST(exportAwards, oneAwardVector) {
    AwardList list;
    list.createAward("test award", 50);
    list.exportAwards("test/AwardListTest3.txt");
    ifstream input;
    input.open("test/AwardListTest3.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskListTest3.txt" << endl;
        return;
    }

    string line;
    getline(input, line);
    EXPECT_EQ(line, "test award`50`0");
    input.close();
}

TEST(exportAwards, emptyVector) {
    AwardList list;
    list.exportAwards("test/AwardListTest3.txt");
    ifstream input;
    input.open("test/AwardListTest3.txt");
    if (!input.is_open()) {
        cout << "Failed to open TaskListTest3.txt" << endl;
        return;
    }

    string name;
    EXPECT_FALSE(getline(input, name, '`'));
    input.close();
}


TEST(search, noTasks)
{
    TaskListGUI list;
    EXPECT_TRUE(list.search("three") == nullptr);
}

TEST(search, twoTasks)
{
    TaskListGUI list;
    list.addTask("two", "chore", "second one", 1, 2, 2022);
    list.addTask("three", "chore", "third one", 1, 4, 2012);
    EXPECT_TRUE(list.search("three") != nullptr);
}

TEST(search, oneTasks)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 4, 2012);
    EXPECT_TRUE(list.search("one") != nullptr);
}

TEST(undoTask, noTasks)
{
    TaskListGUI list;
    list.undoDeleteTask();
    EXPECT_TRUE(list.search("three") == nullptr);
}

TEST(undoTask, oneTasks)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 4, 2012);
    list.deleteTask("one");
    list.undoDeleteTask();
    list.printList();
    EXPECT_TRUE(list.search("one") != nullptr);
}

TEST(undoTask, inMiddleOfList)
{
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 4, 2012);
    list.addTask("two", "chore", "second one", 1, 2, 2022);
    list.addTask("three", "chore", "third one", 1, 4, 2012);
    list.deleteTask("three");
    list.undoDeleteTask();
    EXPECT_TRUE(list.search("three") != nullptr);
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
    list.markOverdue();
    list.showOverdue();
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 5); 
}

TEST(markTaskComplete, otherPoints) {
    TaskListGUI list;
    int points = 0;
    list.addTask("one", "other", "random", 5, 4, 2023);
    char* tm = "Fri Jul 3 00:00:00 2023";
    list.markOverdue();
    list.showOverdue();
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 0); 
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

TEST(createAwardTest, testAwards3) {
    AwardList t1;
    t1.createAward("test award", 50);
    t1.createAward("test award 2", 75);
    t1.createAward("test award 3", 75);
    EXPECT_EQ(t1.getAwardVector().size(), 3);
    EXPECT_EQ(t1.getAwardVector().at(2)->award_name, "test award 3" );
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

TEST(deleteAwardTest, testCorrectAwardDeleted2) {
    AwardList t1;
    t1.createAward("test award", 50);
    t1.createAward("test award 2", 75);
    t1.createAward("test award 3", 100);
    t1.deleteAward("test award");
    t1.deleteAward("test award 2");
    EXPECT_EQ(t1.getAwardVector().size(), 1);
    EXPECT_EQ(t1.getAwardVector().at(0)->award_name, "test award 3");
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
    list.createAward("customTestAward",5);
    list.setTotalPoints(5);
    list.buyAward("customTestAward",1);

    ifstream ifs;
    ifs.open("saved_files/Point_Log.txt",ios::app);
    EXPECT_TRUE(ifs.is_open());

    bool isMsgPresent;
    string logMsg;
    while(getline(ifs,logMsg)) //loops to last line of file
    if(logMsg == "Nice catch there bob! You just bought: 1 WOWOWOW and spent 5 points" || 
        logMsg == "Good eye their chief You just bought: 1 WOWOWOW and spent 5 points" ||
        logMsg == "Congrats! You just bought: 1 WOWOWOW and spent 5 points" || 
        logMsg == "That's a nice treat! You just bought: 1 WOWOWOW and spent 5 points") {
            isMsgPresent = true;
        }
    EXPECT_TRUE(isMsgPresent);
}

TEST(buyAwardTest, testOnlyAward) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.setTotalPoints(10);

    testAwardList.buyAward("cupcake", 1);
    EXPECT_EQ(testAwardList.getTotalPoints(), 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 1);
}

TEST(buyAwardTest, testFrontOfVec) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.createAward("poke", 10);
    testAwardList.createAward("boba", 10);
    testAwardList.setTotalPoints(10);

    testAwardList.buyAward("cupcake", 1);
    EXPECT_EQ(testAwardList.getTotalPoints(), 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 1);
    EXPECT_EQ(testAwardList.getAwardVector().at(1)->user_count, 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(2)->user_count, 0);
}

TEST(buyAwardTest, testMiddleOfVec) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.createAward("poke", 10);
    testAwardList.createAward("boba", 10);
    testAwardList.setTotalPoints(10);

    testAwardList.buyAward("poke", 1);
    EXPECT_EQ(testAwardList.getTotalPoints(), 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(1)->user_count, 1);
    EXPECT_EQ(testAwardList.getAwardVector().at(2)->user_count, 0);
}

TEST(buyAwardTest, testEndOfVec) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.createAward("poke", 10);
    testAwardList.createAward("boba", 10);
    testAwardList.setTotalPoints(10);

    testAwardList.buyAward("boba", 1);
    EXPECT_EQ(testAwardList.getTotalPoints(), 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(1)->user_count, 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(2)->user_count, 1);
}

TEST(buyAwardTest, testMultipleQuantity) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.setTotalPoints(50);

    testAwardList.buyAward("cupcake", 5);
    EXPECT_EQ(testAwardList.getTotalPoints(), 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 5);
}

TEST(buyAwardTest, notEnoughPoints) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.setTotalPoints(5);

    testAwardList.buyAward("cupcake", 1);
    EXPECT_EQ(testAwardList.getTotalPoints(), 5);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 0);
}

TEST(buyAwardTest, quantityTooHigh) {
    AwardList testAwardList;
    testAwardList.createAward("cupcake", 10);
    testAwardList.setTotalPoints(40);

    testAwardList.buyAward("cupcake", 5);
    EXPECT_EQ(testAwardList.getTotalPoints(), 40);
    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 0);
}

TEST(markOverDue, allOnTime) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2024);
    list.addTask("two", "chore", "second one", 3, 6, 2024);
    list.addTask("three", "chore", "third one", 22, 11, 2024);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, false);
    EXPECT_EQ(curr2->overdue, false);
    EXPECT_EQ(curr3->overdue, false);
} 

TEST(markOverDue, allOverdue) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2023);
    list.addTask("two", "chore", "second one", 3, 6, 2023);
    list.addTask("three", "chore", "third one", 2, 11, 2023);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, true);
    EXPECT_EQ(curr2->overdue, true);
    EXPECT_EQ(curr3->overdue, true);
} 

TEST(markOverDue, SomeOverdue) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 1, 1, 2022);
    list.addTask("two", "chore", "second one", 3, 6, 2025);
    list.addTask("three", "chore", "third one", 22, 11, 2021);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.markOverdue();
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, true);
    EXPECT_EQ(curr2->overdue, false);
    EXPECT_EQ(curr3->overdue, true);
} 

TEST(markTaskComplete, testTaskOverdue) {
    TaskListGUI list;
    int points = 0;
    list.addTask("one", "essay", "random", 5, 4, 202);
    char* tm = "Fri Jul 3 00:00:00 2023";
    list.markOverdue();
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 5); 
}

TEST(editingATask, printDateFunc) {
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

// TEST(markComplete, pointLog)
// {
//     TaskListGUI list;
//     list.addTask("one", "chore", "first one", 1, 1, 2022);
//     int points = 5;
//     list.markTaskCompleted("one",points);
//     EXPECT_EQ(points, 10);

// }

TEST(editingATask, editTaskname) {
    TaskList list;
    list.addTask("one", "chore", "first one", 1, 2, 2022);
    list.addTask("two", "essay", "second one", 2, 3, 2023);
    string newDes = "changed";
    list.editTask("two");
    EXPECT_EQ(list.search("three")->name, "changed");
    
}

TEST(useAward, frontOfVec) {
    AwardList testAwardList;

    testAwardList.createAward("cupcake", 10);
    testAwardList.createAward("poke", 10);
    testAwardList.createAward("boba", 10);
    testAwardList.setTotalPoints(30);
    testAwardList.buyAward("cupcake", 1);
    testAwardList.buyAward("poke", 1);
    testAwardList.buyAward("boba", 1);
    testAwardList.useAward("cupcake");

    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(1)->user_count, 1);
    EXPECT_EQ(testAwardList.getAwardVector().at(2)->user_count, 1);
}

TEST(useAward, middleOfVec) {
    AwardList testAwardList;

    testAwardList.createAward("cupcake", 10);
    testAwardList.createAward("poke", 10);
    testAwardList.createAward("boba", 10);
    testAwardList.setTotalPoints(30);
    testAwardList.buyAward("cupcake", 1);
    testAwardList.buyAward("poke", 1);
    testAwardList.buyAward("boba", 1);
    testAwardList.useAward("poke");

    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 1);
    EXPECT_EQ(testAwardList.getAwardVector().at(1)->user_count, 0);
    EXPECT_EQ(testAwardList.getAwardVector().at(2)->user_count, 1);
}

TEST(useAward, endOfVec) {
    AwardList testAwardList;

    testAwardList.createAward("cupcake", 10);
    testAwardList.createAward("poke", 10);
    testAwardList.createAward("boba", 10);
    testAwardList.setTotalPoints(30);
    testAwardList.buyAward("cupcake", 1);
    testAwardList.buyAward("poke", 1);
    testAwardList.buyAward("boba", 1);
    testAwardList.useAward("boba");

    EXPECT_EQ(testAwardList.getAwardVector().at(0)->user_count, 1);
    EXPECT_EQ(testAwardList.getAwardVector().at(1)->user_count, 1);
    EXPECT_EQ(testAwardList.getAwardVector().at(2)->user_count, 0);
}

