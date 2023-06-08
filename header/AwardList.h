#ifndef AWARDLIST_H
#define AWARDLIST_H

#include <iostream>
#include <ostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct Award
{
	int cost;
	int user_count; //amount of this award user has, acts ass message too
	string award_name;
	Award(string name, int cost, int count): award_name(name),cost(cost),user_count(count){};
	Award(): award_name(""), cost(0), user_count(0){};
	string exportAward() //used in exportAwards
	{
		return award_name + '`' + to_string(cost) + '`' + to_string(user_count);
	};
	void displayAward()
	{
		cout << user_count << "     " << cost << "     " << award_name;
	};

};

class AwardList
{
	protected:
		vector<Award*> awardVector;
		int totalPoints;
	public:
		AwardList();
		~AwardList();
		void importAwards(); //import tasks from “AwardsList.txt”
		void exportAwards(); //will write the file within the function named “AwardsList.txt”
		void buyAward(string buyingAward, int quantity); //increases user_count by 1, subtracts from totalPoints, error message if not enough points
		void useAward(string name); //lower user_count by 1, erorr message if 0
		void createAward(string name, int cost); //add award to award list
		void deleteAward(string name); //delete award from list, if it’s already in the list, user_count–
		int getTotalPoints(); //return totalPoints
		void setTotalPoints(int newTotalPoints); //set totalPoints
		void importTotalPoints(); //imports totalPoints
		string congratsMessage(const Award* boughtAward, const int quantity); //prints out a random congratulatory message

	  //for testing
		vector<Award*> getAwardVector();
};
	
#endif
