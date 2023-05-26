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

};

class AwardList
{
	private:
		vector<Award*> awardlist;
		int totalPoints;
	public:
		AwardList();
		void importAwards(); //import tasks from “AwardsList.txt”
		void exportAwards(); //will write the file within the function named “AwardsList.txt”
		int buyAward(string name);//returns cost of ward, this is subtracted from total_points
		void  useAward(string name); //idk what this would be, as of now it just prints a message I think, or the name, also remove it from the list
		void createAward(string name, int cost); //add award to award list, if it’s already in, user_count++, cost can't be <  1
		void deleteAward(string name); //delete award from list, if it’s already in the list, user_count–
		bool inList(string name); //return true if the award is in already in the list, false otherwise
		int getTotalPoints(); //return totalPoints
		void setTotalPoints(); //set totalPoints
};
	
	


#endif
