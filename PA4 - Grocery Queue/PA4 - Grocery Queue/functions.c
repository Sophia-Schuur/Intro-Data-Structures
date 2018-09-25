#include "header.h"


void initQueue(Queue *pHead)
{
	pHead->pHead = pHead->pTail = NULL;
}

NODE * make_node(int cust_num, int serv_time, int total_time)
{
	NODE *pMem = NULL;

	pMem = (NODE *)malloc(sizeof(NODE));

	if (pMem != NULL)
	{
		pMem->pNext = NULL;
		pMem->customerNumber = cust_num;
		pMem->serviceTime = serv_time;
		pMem->totalTime = total_time;
	}

	return pMem;
}

int isEmpty(Queue *queue)
{
	return (queue->pHead == NULL);
}


int enqueue(Queue *pQueue, int cust_num, int serv_time, int total_time)
{
	int success = 0;
	NODE *pMem = NULL;

	pMem = make_node(cust_num, serv_time, total_time);
								 
	if (pMem != NULL)
	{
		success = 1;

		if (pQueue->pHead == NULL) //empty queue
		{
			pQueue->pHead = pQueue->pTail = pMem;
		}
		else //not empty queue
		{
			pQueue->pTail->pNext = pMem;
			pQueue->pTail = pMem;
		}
	}

	return success;
}

void printqueue(Queue pHead)
{
	NODE * pCur = NULL;
	pCur = pHead.pHead;

	while (pCur != NULL)
	{
		printf("Customer number: %d, Service time %d minutes, total waiting time in lane %d minutes\n", pCur->customerNumber, pCur->serviceTime, pCur->totalTime);
		pCur = pCur->pNext;
	}
}

int dequeue(Queue *pQueue)	//will always dequeue from head of list. no need to pass in customer
{
	NODE *pTemp = NULL;
	int customer_num = 0;

		
	if (pQueue != NULL)
	{
		pTemp = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		customer_num = pTemp->customerNumber;
		
		if (pTemp == pQueue->pTail)
		{
			pQueue->pHead = pQueue->pTail = NULL;
		}
		free(pTemp);
	}
	
	return customer_num;
}

int get_minutes(void)
{
	int user_inputted_total_mins = 0;
	printf("Enter number of minutes to run the total simulation.\n");
	scanf("%d", &user_inputted_total_mins);
	return user_inputted_total_mins;
}

