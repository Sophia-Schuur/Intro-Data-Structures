#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

class ExercisePlan
{
public:
	//constructor
	ExercisePlan();

	//copy constructor														
	ExercisePlan(ExercisePlan &copy);

	//destructor
	~ExercisePlan();

	//getters
	string getPlan();
	int getGoalSteps();
	string getDate();

	//setters
	void setPlan(string Plan);
	void setGoalSteps(int GoalSteps);
	void setDate(string Date);

	//edit a plan
	void EditExercisePlan(ExercisePlan Exercise[]);


private:

	string emPlan;
	int emGoalSteps;		//maximum intake of calories for a day is stored here
	string emDate;

};