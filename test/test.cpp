#include "../googletest/googletest/include/gtest/gtest.h"
#include "../header/AwardList.h"
#include "../header/TaskList.h"
#include "../header/TaskListGUI.h"
#include "../header/AwardListGUI.h"
#include<iostream>
#include<fstream>
#include <ostream>
#include <string>
#include <sstream>
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

TEST(markTaskComplete, test) {
    TaskList list;
    int points = 0;
    list.addTask("one", "chore", "random", 5, 4, 2023);
    list.markTaskCompleted("one", points);
    EXPECT_EQ(points, 5);
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

TEST(PrintList, noOverDue) {
    TaskListGUI list;
    list.addTask("one", "chore", "first one", 23, 11, 2023);
    list.addTask("two", "studying", "second one", 14, 11, 2023);
    list.addTask("three", "other", "third one", 22, 11, 2023);
    char* tm = "Fri Aug 15 00:00:00 2023";
    list.showOverdue(tm);
    TaskNode* curr1 = list.search("one");
    TaskNode* curr2 = list.search("two");
    TaskNode* curr3 = list.search("three");
    bool curr1Bool;
    bool curr2Bool;
    bool curr3Bool;
    curr1Bool = (curr1.displayTask() == "      11/23/2023      CHORE      one");
    curr2Bool = (curr2.displayTask() == "      11/14/2023      STUDY      two");
    curr3Bool = (curr2.displayTask() == "      11/22/2023      OTHER      three");
    EXPECT_EQ(curr1Bool, true);
    EXPECT_EQ(curr2Bool, true);
    EXPECT_EQ(curr3Bool, true);
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