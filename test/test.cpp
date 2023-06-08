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
#include <time.h>   
#include "googletest/googletest/include/gtest/gtest.h"    /* time */
using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

     // srand(time(NULL));
    vector<string> names = {"Task 1","Task 2","Task 3","Task 4","Task5"};
    vector<string> tag = {"Tag 1","Tag 2","Tag 3","Tag 4","Tag 5"};
    vector<string> desc = {"Description 1","Description 2","Description 3","Description 4","Description 5"};
    vector<int> year = {2001,2002,2003,2004,2005,};
    TaskListGUI list;

    cout << "UNIT TESTS: " << endl;

    cout << "Adding two tasks" << endl << "BEFORE: ";
    list.printList();
    list.addTask(names.at(0),tag.at(0),desc.at(0), 5,5,2005);
    list.addTask(names.at(1),tag.at(0),desc.at(0), 5,3,2005);
    list.printList();
    cout << "Adding two tasks w/different years" << endl;
    TaskListGUI list2;
    list2.printList();
    list2.addTask(names.at(0),tag.at(0),desc.at(0), 5,5,2005);
    list2.addTask(names.at(1),tag.at(0),desc.at(0), 5,3,2003);
    list2.printList();
    cout << "Adding two tasks with different months and days and the same year" << endl;
    TaskListGUI list3;
    list3.printList();
    list3.addTask(names.at(0),tag.at(0),desc.at(0), 6,2,2005);
    list3.addTask(names.at(1),tag.at(0),desc.at(0), 5,3,2005);
    list3.printList();
    cout << "Adding two tasks where only the day is different" << endl;
    TaskListGUI list4;
    list4.printList();
    list4.addTask(names.at(0),tag.at(0),desc.at(2), 5,2,2005);
    list4.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);
    list4.printList();
    cout << "Adding multiple tasks w/different years" << endl;
    TaskListGUI list5;
    list5.printList();
    list5.addTask(names.at(0),tag.at(0),desc.at(2), 5,2,2005);
    list5.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2003);
    list5.addTask(names.at(2),tag.at(0),desc.at(4), 5,3,2001);
    list5.printList();
    cout << "Adding multiple tasks w/months days and the same year" << endl;
    TaskListGUI list6;
    list6.printList();
    list6.addTask(names.at(0),tag.at(0),desc.at(2), 2,2,2001);
    list6.addTask(names.at(1),tag.at(0),desc.at(3), 3,3,2001);
    list6.addTask(names.at(2),tag.at(0),desc.at(4), 4,5,2001);
    list6.printList();
    cout << "Adding multiple tasks where only the day is different" << endl;
    TaskListGUI list7;
    list7.printList();
    list7.addTask(names.at(0),tag.at(0),desc.at(2), 5,2,2005);
    list7.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);
    list7.addTask(names.at(2),tag.at(0),desc.at(4), 5,24,2005);
    list7.printList();
    cout << "Deleting head" << endl;
    TaskListGUI list8;
    list8.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);    
    list8.printList();
    list8.deleteTask(names.at(1));
    list8.printList();
    cout <<"Deleting tail" << endl;
    TaskListGUI list9;
    list9.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);    
    list9.addTask(names.at(0),tag.at(0),desc.at(3), 5,6,2005);    
    list9.printList();
    list9.deleteTask(names.at(0));
    list9.printList();
    cout << "Deleting head and tail" << endl;
    list9.deleteTask(names.at(0));
    list9.deleteTask(names.at(1));
    list.printList();
    cout << "Deleting in the middle of the list" << endl;
    TaskListGUI list10;
    list10.addTask(names.at(1),tag.at(0),desc.at(3), 5,3,2005);    
    list10.addTask(names.at(0),tag.at(0),desc.at(3), 5,6,2005);  
    list10.addTask(names.at(2),tag.at(0),desc.at(3), 5,7,2005);    
  
    list10.printList();
    list10.deleteTask(names.at(0));
    list10.printList();
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
    list.showOverdue(tm);
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
    list.showOverdue(tm);
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    EXPECT_EQ(curr1->overdue, true);
    EXPECT_EQ(curr2->overdue, true);
    EXPECT_EQ(curr3->overdue, false);
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
