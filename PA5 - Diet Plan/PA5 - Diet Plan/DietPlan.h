#pragma once

#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;


class DietPlan
{

public:
	//constructor
	DietPlan();

	//copy constructor														
	DietPlan(DietPlan &copy);

	//destructor
	~DietPlan();							
	
	//getters
	string getPlan();
	int getGoalCalories();
	string getDate();
	
	//setters
	void setPlan(string Plan);
	void setGoalCalories(int GoalCalories);
	void setDate(string Date);
	
	void EditDietPlan(/*fstream &file, */DietPlan Diet[]);
	//insert editGoal();

	

private:
	
	string mPlan;
	int mGoalCalories;		//maximum intake of calories for a day is stored here
	string mDate;
	 
};

//read
//create object
//get info from object getters return values
//set info 

