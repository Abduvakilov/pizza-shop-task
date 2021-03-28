#include <stdio.h>
#include <stdlib.h>
#include "order.h"
#include "oven.h"

// PIZZA_ARRAY_SIZE defined in oven.h
unsigned char largePizzaCookTime = 4;
unsigned char smallPizzaCookTime = 6;


unsigned char ovenCount = 0;

struct Oven* createOven()
{
	struct Oven* oven = (struct Oven*)malloc(sizeof(struct Oven));
	oven->status = EMPTY;
	oven->queue = (struct OvenQueue*)malloc(sizeof(struct OvenQueue));
	oven->queue->front = 0;
	oven->queue->rear = -1;
	oven->queue->itemCount = 0;
	oven->queue->lastPizzaFinishTime = 0;
	ovens[ovenCount] = oven;
	ovenCount++;
	return oven;
}

void createOvens(int count)
{
	int ovensToMax = OVEN_ARRAY_SIZE - ovenCount;
	count = ovensToMax >  count ? count : ovensToMax;
	for(int i=0; i < count; i++)
	{
		createOven();
	}
}

unsigned char getCookTime(enum PizzaSize pizza)
{
	switch(pizza)
	{
		case SMALL:
			return smallPizzaCookTime;
		case LARGE:
			return largePizzaCookTime;
	}
}

bool oqIsEmpty(struct OvenQueue* queue)
{
   return queue->itemCount == 0;
}

bool oqIsFull(struct OvenQueue* queue)
{
   return queue->itemCount == PIZZA_ARRAY_SIZE;
}

int oqSize(struct OvenQueue* queue)
{
   return queue->itemCount;
}

unsigned long addToOvenQueue(struct OvenQueue* queue, struct PizzaOrder* pizzaOrder)
{
	if(oqIsFull(queue))
	{
	  printf("Cannot add. %d items in Oven Queue\n", queue->itemCount);
	  return 0;
	}

	if(queue->rear == PIZZA_ARRAY_SIZE-1)
	{
	  printf("Queue array starting over\n");
	  queue->rear = -1;
	}

	queue->pizzaOrder[++queue->rear] = pizzaOrder;
	queue->itemCount++;
	pizzaOrder->cookStartTime = queue->lastPizzaFinishTime;
	pizzaOrder->readyTime = queue->lastPizzaFinishTime +
								 getCookTime(pizzaOrder->pizzaSize);
	queue->lastPizzaFinishTime = pizzaOrder->readyTime;
	return queue->lastPizzaFinishTime;
}

struct Oven* getFistFinishingOven()
{
	struct Oven* rOven = ovens[0];
	if (ovenCount == 1)
		return rOven;
	unsigned long minFinishTime = rOven->queue->lastPizzaFinishTime;
	for(int i=1;i<ovenCount;i++)
	{
		struct Oven* oven = ovens[i];
		if (oven->queue->lastPizzaFinishTime < minFinishTime)
		{
			minFinishTime = oven->queue->lastPizzaFinishTime;
			rOven = oven;
		}
	}
	return rOven;
}

int getTotalPizzaQuantity(struct Order* order)
{
	return order->smallPizzaQuantity + order->largePizzaQuantity;
}

struct PizzaOrder* ctreatePizzaOrder(int pizzaIndex, struct Order* order)
{
	struct PizzaOrder* pizzaOrder = (struct PizzaOrder*)malloc(sizeof(struct PizzaOrder));
	pizzaOrder->pizzaSize = pizzaIndex > order->smallPizzaQuantity ? LARGE : SMALL;
	pizzaOrder->order = order;
	return pizzaOrder;
}

void enqueueOrder(struct Order* order)
{
	unsigned long orderReadyTime = 0;
	const int total = getTotalPizzaQuantity(order);
	for(int i=0; i<total; i++)
	{
		struct Oven* oven = getFistFinishingOven();
		struct PizzaOrder* pizzaOrder = ctreatePizzaOrder(i, order);
		orderReadyTime = addToOvenQueue(oven->queue, pizzaOrder);
	}
	order->readyTime = orderReadyTime;
	printf("Order %d ready time: %lu\n", order->id, order->readyTime);
}
