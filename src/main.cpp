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

//global


int main() {
    /*Imports total_points*/
    ifstream total_points_file("../saved_files/Total_Points.txt");
    int total_points = 0;
    total_points_file >> total_points;
    
    return 0;
}