#include <stdio.h>
#include <stdlib.h>
#include "order.h"
#include "oven.h"
#include "timestamp.h"

// unsigned char largePizzaCookTime = 4;
// unsigned char smallPizzaCookTime = 6;

#define QUEUE_ARRAY_SIZE 120

unsigned char ovensCount = 0;

struct Oven* createOven()
{
	struct Oven* oven = (struct Oven*)malloc(sizeof(struct Oven));	
	oven->status = EMPTY;
	oven->queue = (struct OvenQueue*)malloc(sizeof(struct OvenQueue));	
	oven->queue->front = 0;
	oven->queue->rear = -1;
	oven->queue->itemCount = 0;
	oven->queue->lastOrderFinishTime = 0;
	ovens[ovensCount] = oven;
	ovensCount++;
	return oven;
}

void createOvens(int count)
{
	int ovensToMax = OVEN_ARRAY_SIZE - ovensCount;
	count = ovensToMax >  count ? count : ovensToMax;
	for(int i=0; i < count; i++)
	{
		createOven();
	}
}


bool oqIsEmpty(struct Oven* oven)
{
   return queue->itemCount == 0;
}

bool oqIsFull()
{
   return queue->itemCount == QUEUE_ARRAY_SIZE;
}

int oqSize(struct OvenQueue* queue)
{
   return queue->itemCount;
}

void addToOvenQueue(struct OvenQueue* queue, struct Order* order)
{
   if(oqIsFull(queue))
   {
      printf("Cannot add. Queue is full\n");
      return;
   }

   if(queue->Rear == QUEUE_ARRAY_SIZE-1)
   {
      printf("Queue array starting over\n");
      qRear = -1;            
   }

   printf("Adding order to queue\n");
   queue[++qRear] = order;
   qItemCount++;
	struct OvenQueue* queue = oven->queue;
	queue
	queue->lastOrderFinishTime = getTimestampB() + cookTime;
}

struct Oven* getFistFinishingOven()
{
	struct Oven* rOven = ovens[0];
	if (ovensCount == 1)
		return rOven;
	unsigned long minFinishTime = rOven->queue->lastOrderFinishTime;
	for(int i=1;i<ovensCount;i++)
	{
		struct Oven* oven = ovens[i];
		if (oven->queue->lastOrderFinishTime < minFinishTime)
		{
			minFinishTime = oven->queue->lastOrderFinishTime;
			rOven = oven;
		}
	}
	return rOven;
}
