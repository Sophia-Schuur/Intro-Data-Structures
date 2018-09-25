//Sophia Schuur
//CptS 122
//2/20/2017
//PA4 - Simulate two grocery queues

#include "header.h"


//Credit to him for help!
int main(void)
{
	srand((unsigned int)time(NULL));
	Queue pQueue_express, pQueue_normal;
	initQueue(&pQueue_express);
	initQueue(&pQueue_normal);


	int user_inputted_total_mins = 0, total_customer_count = 0, service_time_express = 0, service_time_normal = 0, arrival_time_express = 0, arrival_time_normal = 0, customer_number_dequeue_express = 0, customer_number_dequeue_normal = 0, express_count = 0, normal_count = 0, minutes = 0;

	printf("Let's simulate a grocery line!\n");

	user_inputted_total_mins = get_minutes();
	system("cls");


	for (minutes = 0; minutes < user_inputted_total_mins; minutes++)
	{
		total_customer_count += 1;
		if (total_customer_count == 1440)
		{
			total_customer_count = 0;
		}


		service_time_express = (rand() % 5) + 1;
		service_time_normal = (rand() % 5) + 3;

		arrival_time_express = (rand() % 5) + 1;
		arrival_time_normal = (rand() % 5) + 3;

		if (minutes >= 1)
		{
			if ((minutes % 10 == 0))
			{
				printf("\nEXPRESS LANE TEN MINUTE COUNT:\n");
				printqueue(pQueue_express);
				printf("\nNORMAL LANE TEN MINUTE COUNT:\n");
				printqueue(pQueue_normal);

			}
		}
		arrival_time_express = +service_time_express;
		printf("Express queue customer %d arrives in express lane with service time %d at time %d\n", total_customer_count, service_time_express, minutes);
		enqueue(&pQueue_express, total_customer_count, service_time_express, express_count);


		arrival_time_normal += service_time_normal;
		printf("Normal queue customer %d arrives in normal lane with service time %d at time %d\n", total_customer_count, service_time_normal, minutes);
		enqueue(&pQueue_normal, total_customer_count, service_time_normal, normal_count);
		express_count++;
		normal_count++;

		if ((pQueue_express.pHead != NULL) && (pQueue_express.pHead->serviceTime == express_count))
		{
			express_count = 0;
			customer_number_dequeue_express = dequeue(&pQueue_express);
			printf("\nCustomer %d done with shopping in express lane\n\n", customer_number_dequeue_express);
		}

		if ((pQueue_normal.pHead != NULL) && (pQueue_normal.pHead->serviceTime == normal_count))
		{
			express_count = 0;
			customer_number_dequeue_normal = dequeue(&pQueue_normal);
			printf("\nCustomer %d done with shopping in normal lane\n\n", customer_number_dequeue_normal);
		}

	}
	return 0;
}