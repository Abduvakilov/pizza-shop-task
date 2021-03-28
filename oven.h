#ifndef OVEN_H
#define OVEN_H
#include "order.h"

#define PIZZA_ARRAY_SIZE 500
#define OVEN_ARRAY_SIZE 20

enum PizzaSize { SMALL, LARGE };

unsigned char ovenCount;

enum OvenStatus { EMPTY, COOKING };

unsigned char largePizzaCookTime;
unsigned char smallPizzaCookTime;

struct PizzaOrder
{
	enum PizzaSize pizzaSize;
	struct Order* order;
	unsigned long cookStartTime;
	unsigned long readyTime;
};

struct OvenQueue
{
	unsigned short front;
	unsigned short rear;
	unsigned short itemCount;
	unsigned short lastPizzaFinishTime;
	struct PizzaOrder* pizzaOrder[PIZZA_ARRAY_SIZE];
};

struct Oven
{
	enum OvenStatus status;
	struct OvenQueue* queue;
};

struct Oven* ovens[OVEN_ARRAY_SIZE];

// struct Oven* createOven();
void createOvens(int count);
// unsigned short calculateOvenTime(struct Order* order);
// void cook(struct Oven* oven, struct Order* order);
struct Oven* getFistFinishingOven();
void enqueueOrder(struct Order* order);

#endif
