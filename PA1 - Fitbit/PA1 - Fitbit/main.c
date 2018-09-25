//Sophia Schuur
//PA 1
//1/15/2017
//Analyzing data of a fake fitbit app. Intro to structs


#include "header.h"

int main(void)
{
	//had issue with the original file format so i created a new text file and copied all the data from the csv file into the text file just as it was.
	FILE *FitbitData = NULL;
	FitbitData = fopen("FitbitData.txt", "r");

	FILE *Results = NULL;
	Results = fopen("Results.txt", "w");

	DATA data[1440] = { 0,0,0,0,0,0,0 };
	char str[100];
	double calorie_count = 0.0, distance_count = 0.0, average_heartrate_count;
	int floors_count = 0, steps_count = 0, max_steps = 0, sum_sleep;

	//DETERMINE IF FILES OPENED SUCCESSFULLY OR NOT
	if (FitbitData == NULL)
	{
		printf("ERROR OPENING FILE\n");
	}
	else
	{
		printf("FILE OPENED SUCCESSFULLY\n");
	}
	
	//READ AND COUNT
	read_file(FitbitData, data, str);
	calorie_count = count_total_calories(data);
	distance_count = count_total_distance(data);
	floors_count = count_total_floors(data);
	steps_count = count_total_steps(data);
	average_heartrate_count = average_heartrate(data);
	max_steps = max_steps_taken(data);
	sum_sleep = longest_sleep(data);
	
	
	
	//PRINT RESULTS TO FILE
	fprintf(Results, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(Results, "%lf,%lf,%d,%d,%lf,%d,%d", calorie_count, distance_count, floors_count, steps_count, average_heartrate_count, max_steps, sum_sleep);
	
	fprintf(Results, "TOTAL CALORIES: %lf\n", calorie_count);
	fprintf(Results, "TOTAL DISTANCE: %lf\n", distance_count);
	fprintf(Results, "TOTAL FLOORS: %d\n", floors_count);
	fprintf(Results, "TOTAL STEPS: %d\n", steps_count);
	fprintf(Results, "AVERAGE HEARTRATE: %lf\n", average_heartrate_count);
	fprintf(Results, "MAX STEPS TAKEN: %d\n", max_steps);
	fprintf(Results, "LONGEST CONSECUTIVE RANGE OF POOR SLEEP: %d\n", sum_sleep);

	//PRINT RESULTS TO SCREEN
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	printf("%lf,%lf,%d,%d,%lf,%d,%d", calorie_count, distance_count, floors_count, steps_count, average_heartrate_count, max_steps, sum_sleep);
	
	printf("TOTAL CALORIES: %lf\n", calorie_count);
	printf("TOTAL DISTANCE: %lf\n", distance_count);
	printf("TOTAL FLOORS: %d\n", floors_count);
	printf("TOTAL STEPS: %d\n", steps_count);
	printf("AVERAGE HEARTRATE: %lf\n", average_heartrate_count);
	printf("MAX STEPS TAKEN: %d\n", max_steps);
	printf("LONGEST CONSECUTIVE RANGE OF POOR SLEEP: %d\n", sum_sleep);


	
	//CLOSE FILES
	fclose(FitbitData);
	fclose(Results);
	
	
	return 0;
}

