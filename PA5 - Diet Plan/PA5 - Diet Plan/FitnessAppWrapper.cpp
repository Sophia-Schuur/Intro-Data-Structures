#include "FitnessAppWrapper.h"


//OVERLOADED OPERATORS FOR INPUT AND OUTPUTTING TO FILE
ifstream & operator >> (ifstream &infile, DietPlan &Diet)
{
	int goal;										//had weird issue with the slashes. friend helped me out on this function.
	string plan, date, month, day, year, end;

	getline(infile, plan);
	getline(infile, end);
	goal = stoi(end);
	getline(infile, month, '/');
	getline(infile, day, '/');
	getline(infile, year);
	getline(infile, end);
	date = month + '/' + day + '/' + year;

	Diet.setPlan(plan);
	Diet.setGoalCalories(goal);
	Diet.setDate(date);

	return infile;

}

ofstream & operator << (ofstream &outfile, DietPlan &Diet)
{
	outfile << Diet.getPlan() << endl << Diet.getGoalCalories() << endl << Diet.getDate() << endl;
	return outfile;
}

ifstream & operator >> (ifstream &infile, ExercisePlan &Exercise)
{
	int goal;										//had weird issue with the slashes. friend helped me out on this function.
	string plan, date, month, day, year, end;

	getline(infile, plan);
	getline(infile, end);
	goal = stoi(end);
	getline(infile, month, '/');
	getline(infile, day, '/');
	getline(infile, year);
	getline(infile, end);
	date = month + '/' + day + '/' + year;

	Exercise.setPlan(plan);
	Exercise.setGoalSteps(goal);
	Exercise.setDate(date);

	return infile;

}

ofstream & operator << (ofstream &outfile, ExercisePlan &Exercise)
{
	outfile << Exercise.getPlan() << endl << Exercise.getGoalSteps() << endl << Exercise.getDate() << endl;
	return outfile;
}


//LOAD DAILY DIET PLAN
void FitnessAppWrapper::LoadDailyDietPlan(ifstream &infile, DietPlan Diet[], int index)
{
	infile >> Diet[index];
}

//LOAD WEEKLY DIET PLAN
void FitnessAppWrapper::LoadWeeklyDietPlan(ifstream &infile, DietPlan Diet[])
{
	int index = 0;
	while (index < 7)
	{
		infile >> Diet[index];
		index++;
	}
}

//DISPLAY DAILY DIET PLAN TO THE SCREEN
void FitnessAppWrapper::DisplayDailyDietPlan(DietPlan Diet[], int index)
{
	cout << Diet[index].getPlan() << endl;
	cout << Diet[index].getGoalCalories() << endl;
	cout << Diet[index].getDate() << endl;
	cout << endl;
}

//DISPLAY WEEKLY DIET PLAN TO THE SCREEN
void FitnessAppWrapper::DisplayWeeklyDietPlan(DietPlan Diet[])
{
	int index = 0;
	while (index < 7)
	{
		DisplayDailyDietPlan(Diet, index);
		index++;
	}
}

//STORE DAILY DIET PLAN TO FILE
void FitnessAppWrapper::StoreDailyDietPlan(ofstream &outfile, DietPlan Diet[], int index)
{
	outfile << Diet[index].getPlan() << endl;
	outfile << Diet[index].getGoalCalories() << endl;
	outfile << Diet[index].getDate() << endl;
	outfile << endl;
}

//STORE WEEKLY DIET PLAN TO FILE
void FitnessAppWrapper::StoreWeeklyDietPlan(ofstream &outfile, DietPlan Diet[])
{
	int index = 0;
	while (index < 7)
	{
		StoreDailyDietPlan(outfile, Diet, index);
		index++;
	}
	
}




//LOAD DAILY EXERCISE PLAN
void FitnessAppWrapper::LoadDailyExercisePlan(ifstream &infile, ExercisePlan Exercise[], int index)
{
	infile >> Exercise[index];
}

//LOAD WEEKLY EXERCISE PLAN
void FitnessAppWrapper::LoadWeeklyExercisePlan(ifstream &infile, ExercisePlan Exercise[])
{
	int index = 0;
	while (index < 7)
	{
		infile >> Exercise[index];
		index++;
	}
}

//DISPLAY DAILY EXERCISE PLAN TO THE SCREEN
void FitnessAppWrapper::DisplayDailyExercisePlan(ExercisePlan Exercise[], int index)
{
	cout << Exercise[index].getPlan() << endl;
	cout << Exercise[index].getGoalSteps() << endl;
	cout << Exercise[index].getDate() << endl;
	cout << endl;
}

//DISPLAY WEEKLY EXERCISE PLAN TO THE SCREEN
void FitnessAppWrapper::DisplayWeeklyExercisePlan(ExercisePlan Exercise[])
{
	int index = 0;
	while (index < 7)
	{
		DisplayDailyExercisePlan(Exercise, index);
		index++;
	}
}

//STORE DAILY EXERCISE PLAN TO FILE
void FitnessAppWrapper::StoreDailyExercisePlan(ofstream &outfile, ExercisePlan Exercise[], int index)
{
	outfile << Exercise[index].getPlan() << endl;
	outfile << Exercise[index].getGoalSteps() << endl;
	outfile << Exercise[index].getDate() << endl;
	outfile << endl;
}

//STORE WEEKLY EXERCISE PLAN TO FILE
void FitnessAppWrapper::StoreWeeklyExercisePlan(ofstream &outfile, ExercisePlan Exercise[])
{
	int index = 0;
	while (index < 7)
	{
		StoreDailyExercisePlan(outfile, Exercise, index);
		index++;
	}

}



//DISPLAY HOME MENU
void displayMenu()
{
	cout << "1. Load weekly diet plan from file" << endl;
	cout << "2. Load weekly exercise plan from file" << endl;
	cout << "3. Store weekly diet plan to file" << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly exercise plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily exercise plan" << endl;
	cout << "9. Exit." << endl;   // Note: this must write the most recent weekly plans to the corresponding files.
}
