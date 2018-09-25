//Sophia Schuur
//CptS 122
//2/23/2017
//PA5 - Diet plan


#include "FitnessAppWrapper.h"
#include "ExercisePlan.h"
#include "DietPlan.h"

int main(void)
{
	FitnessAppWrapper Dietplan;
	DietPlan Diet[7];
	DietPlan Edit_Diet_Plan;

	FitnessAppWrapper Exerciseplan;
	ExercisePlan Exercise[7];
	ExercisePlan Edit_Exercise_Plan;

	int choice = 0;
	
	
	ifstream DietInfile;
	DietInfile.open("dietPlans.txt");
	ofstream DietOutfile;

	ifstream ExerciseInfile;
	ExerciseInfile.open("exercisePlans.txt");
	ofstream ExerciseOutfile;

	char goback = 'y';

	


	while (goback == 'y')
	{
		displayMenu();
		cin >> choice;
		switch (choice)
		{


		case LOAD_DIET:
			system("cls");
			
			cout << "Diet Plans loaded." << endl;
			
			Dietplan.LoadWeeklyDietPlan(DietInfile, Diet);

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			DietInfile.close();
			break;

		case LOAD_EXERCISE:
			system("cls");

			cout << "Exercise Plans loaded." << endl;

			Exerciseplan.LoadWeeklyExercisePlan(ExerciseInfile, Exercise);

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			ExerciseInfile.close();

			break;

		

		case STORE_DIET:
			
			DietOutfile.open("dietPlans.txt");
			Dietplan.StoreWeeklyDietPlan(DietOutfile, Diet);
			cout << "Data stored to diet plan file. Exiting program." << endl;

			goback = 'n';
			DietOutfile.close();

			break;

		case STORE_EXERCISE:

			ExerciseOutfile.open("exercisePlans.txt");
			Exerciseplan.StoreWeeklyExercisePlan(ExerciseOutfile, Exercise);
			cout << "Data stored to exercise plan file. Exiting program." << endl;

			goback = 'n';
			ExerciseOutfile.close();
			break;

		case DISPLAY_DIET:
			system("cls");
			Dietplan.DisplayWeeklyDietPlan(Diet);

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");

			break;

		case DISPLAY_EXERCISE:
			system("cls");
			Exerciseplan.DisplayWeeklyExercisePlan(Exercise);

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");



			break;

		case EDIT_DIET_PLAN:
			system("cls");
			Edit_Diet_Plan.EditDietPlan(Diet);

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			break;
		case EDIT_EXERCISE_PLAN:

			system("cls");
			Edit_Exercise_Plan.EditExercisePlan(Exercise);

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");


			

			break;
		case EXIT:
			goback = 'n';
			break;
		}
	}
	return 0;
}