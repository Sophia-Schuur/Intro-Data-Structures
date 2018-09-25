#include "DietPlan.h"



//CONSTRUCTOR FOR DIETPLAN OBJECT
DietPlan::DietPlan()
{
	this->mDate = "";
	this->mPlan = "";
	this->mGoalCalories = 0;
}

//COPY CONSTRUCTOR
DietPlan::DietPlan(DietPlan &copy)
{
	setPlan(copy.getPlan());
	setGoalCalories(copy.getGoalCalories());
	setDate(copy.getDate());
}

//DESTRUCTOR FOR DIETPLAN
DietPlan::~DietPlan()			//destructor
{
	/*cout << "Inside destructor for DietPlan" << endl;*/
}

//GET PLAN NAME
string DietPlan::getPlan(void)
{
	return mPlan;
}

//GET CALORIE GOAL
int DietPlan::getGoalCalories(void) 
{
	return mGoalCalories;
}

//GET DATE
string DietPlan::getDate(void)
{
	return mDate;
}

//SET PLAN NAME
void DietPlan::setPlan(string Plan)
{
	mPlan = Plan;
}

//SET CALORIE GOAL
void DietPlan::setGoalCalories(int GoalCalories)
{
	mGoalCalories = GoalCalories;
}

//SET DATE
void DietPlan::setDate(string Date)
{
	mDate = Date;
}

//EDIT A PLAN
void DietPlan::EditDietPlan(/*fstream &file, */DietPlan Diet[])
{
	int diet_plan, index = 0, flag = 0, DietPlanSelection = 0;
	string NewPlan = "\0", NewDate = "\0";
	int NewGoal = 0;
	
	cout << "Which diet plan would you like to edit? Enter an index 0-6." << endl;
	cin >> diet_plan;
	DietPlanSelection = diet_plan;
	while (index < 7 /*&& (flag = 0)*/)
	{
		if (DietPlanSelection == index || diet_plan == index)
		{
			flag = 1;
			cout << "Enter new plan:" << endl;
			cin >> NewPlan;
			Diet[index].setPlan(NewPlan);
			
			cout << "Enter new calorie goal:" << endl;
			cin >> NewGoal;
			Diet[index].setGoalCalories(NewGoal);

			cout << "Enter new date:" << endl;
			cin >> NewDate;
			Diet[index].setDate(NewDate);
			break;

		}
		index++;
	}
	

}