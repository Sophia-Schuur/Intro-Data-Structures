#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
	struct node *pNext;

} NODE;

typedef struct queue
{
	NODE *pHead;
	NODE *pTail;

} Queue;

void initQueue(Queue *pHead);
NODE * make_node(int cust_num, int serv_time, int total_time);
int isEmpty(Queue *queue);
int enqueue(Queue *pQueue, int cust_num, int serv_time, int total_time);
int dequeue(Queue *pQueue);
int get_minutes(void);