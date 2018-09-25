
#include <stdio.h>
#include <stdlib.h>

#include <string.h>






typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

} Sleep;


typedef struct fitbit
{
	
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;

} DATA;


void read_file(FILE*infile, DATA data[], char str[]);
double count_total_calories(DATA data[]);
double count_total_distance(DATA data[]);
int count_total_floors(DATA data[]);
int count_total_steps(DATA data[]);
double average_heartrate(DATA data[]);
int max_steps_taken(DATA data[]);
int longest_sleep(DATA data[]);