#include "ExercisePlan.h"

//CONSTRUCTOR FOR EXERCISE OBJECT
ExercisePlan::ExercisePlan()
{
	this->emDate = "";
	this->emPlan = "";
	this->emGoalSteps = 0;
}

//COPY CONSTRUCTOR
ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	setPlan(copy.getPlan());
	setGoalSteps(copy.getGoalSteps());
	setDate(copy.getDate());
}

//DESTRUCTOR FOR EXERCISE PLAN
ExercisePlan::~ExercisePlan()			
{
	//cout << "Inside destructor for ExercisePlan" << endl;
}

//GET PLAN NAME
string ExercisePlan::getPlan(void)
{
	return emPlan;
}

//GET CALORIE GOAL
int ExercisePlan::getGoalSteps(void)
{
	return emGoalSteps;
}

//GET DATE
string ExercisePlan::getDate(void)
{
	return emDate;
}

//SET PLAN NAME
void ExercisePlan::setPlan(string Plan)
{
	emPlan = Plan;
}

//SET CALORIE GOAL
void ExercisePlan::setGoalSteps(int GoalSteps)
{
	emGoalSteps = GoalSteps;
}

//SET DATE
void ExercisePlan::setDate(string Date)
{
	emDate = Date;
}

//EDIT AN EXERCISE PLAN
void ExercisePlan::EditExercisePlan(ExercisePlan Exercise[])
{
	int exercise_plan, index = 0, flag = 0, ExercisePlanSelection = 0;
	string NewPlan = "\0", NewDate = "\0";
	int NewGoal = 0;

	cout << "Which exercise plan would you like to edit? Enter an index 0-6." << endl;
	cin >> exercise_plan;
	ExercisePlanSelection = exercise_plan;
	while (index < 7 /*&& (flag = 0)*/)
	{
		if (ExercisePlanSelection == index || exercise_plan == index)
		{
			flag = 1;
			cout << "Enter new plan:" << endl;
			cin >> NewPlan;
			Exercise[index].setPlan(NewPlan);

			cout << "Enter new calorie goal:" << endl;
			cin >> NewGoal;
			Exercise[index].setGoalSteps(NewGoal);

			cout << "Enter new date:" << endl;
			cin >> NewDate;
			Exercise[index].setDate(NewDate);
			break;

		}
		index++;
	}


}