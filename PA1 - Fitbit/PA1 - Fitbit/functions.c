#include "header.h"


//READ IN FILE, PARSE DATA AND PLACE INTO APPROPRIATE STRUCT
void read_file(FILE*infile, DATA data[], char str[])
{
	int x = 0, index = 0, counter = 0, i = 0;
	
	/*char token[20] = { '\0' };*/
	char *token = NULL;
	char newstr[100] = { '\0' };
	while (i < 1440)
	{
		/*token = */fgets(str, 100, infile);
		
		int index2 = 0;
		

		//INITIALIZE NEWSTR WITH ZEROES
		for (x = 0; x < strlen(str); x++)
		{
			newstr[x] = 0;
		}


		//INSERT ZERO INTO MISSING HEARTRATE
		int n = 0;
		for (int j = 0; j < strlen(str); j++)				//template from marshall!
		{
			if (str[j] == ',' && str[j] == str[j + 1])
			{
				newstr[j + n] = str[j];
				newstr[j + 1 + n] = '0';
				n++;
			}
			else if (str[j] >= 32 && str[j] <= 126)
			{
				newstr[j + n] = str[j];
			}
		}
		/*printf("%s\n", newstr);*/

		
		//INSERT ZERO INTO MISSING SLEEPLEVEL
		int length = strlen(newstr);
		if (newstr[length - 1] == ',')
		{
			strcat(newstr, "0");
			/*printf("%s", newstr);*/
		}

		
		
		//FIRST TOKEN - MINUTES
		token = strtok(newstr, ",");
		*data->minute = token;
	
		//READ IN CALORIES
			token = strtok(NULL, ",");
			data[i].calories = atof(token);
			/*printf("%lf\n", data[i].calories);*/

		//READ IN DISTANCE
			token = strtok(NULL, ",");
			data[i].distance = atof(token);
			/*printf("%lf\n", data[i].distance);*/

		//READ IN FLOORS
			token = strtok(NULL, ",");
			data[i].floors = atoi(token);
			/*printf("%d\n", data[i].floors);*/

		//READ IN HEARTRATE
			token = strtok(NULL, ",");
			data[i].heartRate = atoi(token);
			/*printf("%d\n", data[i].heartRate);*/
	
	
		//READ IN STEPS
			token = strtok(NULL, ",");
			data[i].steps = atoi(token);
			/*printf("%d\n", data[i].steps);*/

		//READ IN SLEEP LEVEL
			token = strtok(NULL, ",");
			data[i].sleepLevel = atoi(token);
			/*printf("%d\n\n", data[i].sleepLevel);*/
		
		i++;
	}
}

//COUNT TOTAL NUMBER OF CALORIES
double count_total_calories(DATA data[])
{
	int i = 0;
	double calorie_count = 0.0;
	for (i = 0; i < 1440; i++)
	{
		calorie_count += data[i].calories;
		
	}
	return calorie_count;
	/*printf("%lf", calorie_count);*/
}

//COUNT TOTAL DISTANCE
double count_total_distance(DATA data[])
{
	int i = 0;
	double distance_count = 0.0;
	for (i = 0; i < 1440; i++)
	{
		distance_count = distance_count + data[i].distance;
		
	}return distance_count;
}

//COUNT TOTAL FLOORS
int count_total_floors(DATA data[])
{
	int i = 0;
	int floors_count = 0;
	for (i = 0; i < 1440; i++)
	{
		floors_count = floors_count + data[i].floors;
		
	}return floors_count;
}

//COUNT TOTAL STEPS
int count_total_steps(DATA data[])
{
	int i = 0;
	int steps_count = 0;
	for (i = 0; i < 1440; i++)
	{
		steps_count = steps_count + data[i].steps;
		
	}return steps_count;
}

//COUNT AVERAGE HEARTRATE OVER 24 HOURS
double average_heartrate(DATA data[])
{
	int i = 0;
	int heartrate_count = 0;
	double average = 0;
	for (i = 0; i < 1440; i++)
	{
		heartrate_count += data[i].heartRate;
		
	}
	average = (double)heartrate_count / 1440;

	return average;
}

//COUNT MAXIMUM NUMBER OF STEPS TAKEN OVER ONE MINUTE
int max_steps_taken(DATA data[])
{
	int i = 0, max = 0;
	for (i = 0; i < 1339; i++)
	{
		if (data[i].steps > max)
		{
			max = data[i].steps;
		}
		
	}return max;
}

//COUNT LONGEST CONSECUTIVE POOR SLEEP RANGE
int longest_sleep(DATA data[])//a range is defined as one or more consecutive minutes where the sleepLevel > 1; 
								//the poorest sleep is not based on the length of the range, but the sum of the sleep levels in the range; 
								//the max sum of the ranges is considered the poorest sleep
{
	int i = 0, count = 1, max = 0, sum = 0;
	
	for (i = 0; i < 1440; i++)										//worked with classmates 
	{
		if (data[i].sleepLevel > 1 && data[i + 1].sleepLevel > 1)
		{
			count++;

			sum = data[i].sleepLevel + sum;
		}

		if (sum > max)
		{
			max = sum;
			sum = 0;
		}

		if (max < count)
		{
			max = count;
			count = 1;
		}
	}
	return sum;
}

