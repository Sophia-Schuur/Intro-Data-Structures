#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "ExercisePlan.h"
#include "DietPlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;


#define LOAD_DIET 1
#define LOAD_EXERCISE 2
#define STORE_DIET 3
#define STORE_EXERCISE 4
#define DISPLAY_DIET 5
#define DISPLAY_EXERCISE 6
#define EDIT_DIET_PLAN 7
#define EDIT_EXERCISE_PLAN 8
#define EXIT 9

class FitnessAppWrapper
{

public:
	
	//functions for DietPlan
	void LoadDailyDietPlan(ifstream &infile, DietPlan Diet[], int index);
	void LoadWeeklyDietPlan(ifstream &infile, DietPlan Diet[]);

	void DisplayDailyDietPlan(DietPlan Diet[], int index);
	void DisplayWeeklyDietPlan(DietPlan Diet[]);

	void StoreDailyDietPlan(ofstream &outfile, DietPlan Diet[], int index);
	void StoreWeeklyDietPlan(ofstream &outfile, DietPlan Diet[]);


	//functions for ExercisePlan
	void LoadDailyExercisePlan(ifstream &infile, ExercisePlan Exercise[], int index);
	void LoadWeeklyExercisePlan(ifstream &infile, ExercisePlan Exercise[]);

	void DisplayDailyExercisePlan(ExercisePlan Exercise[], int index);
	void DisplayWeeklyExercisePlan(ExercisePlan Exercise[]);

	void StoreDailyExercisePlan(ofstream &outfile, ExercisePlan Exercise[], int index);
	void StoreWeeklyExercisePlan(ofstream &outfile, ExercisePlan Exercise[]);



private:
	//DietPlan Diet[7];
};


ifstream & operator >> (ifstream &infile, DietPlan &Diet);
ofstream & operator << (ofstream &outfile, DietPlan &Diet);

ifstream & operator >> (ifstream &infile, ExercisePlan &Exercise);
ofstream & operator << (ofstream &outfile, ExercisePlan &Exercise);

void displayMenu();