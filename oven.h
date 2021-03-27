#ifndef OVEN_H
#define OVEN_H
#include "order.h"

#define OVEN_ARRAY_SIZE 20

unsigned char ovensCount;

enum OvenStatus { EMPTY, COOKING };

unsigned char largePizzaCookTime;
unsigned char smallPizzaCookTime;

struct OvenQueue
{
	enum pizzaSizes queue[QUEUE_ARRAY_SIZE];
	unsigned char front;
	unsigned char rear;
	unsigned char itemCount;
	unsigned short lastPizzaFinishTime;
};

struct Oven
{
	enum OvenStatus status;
	// unsigned long timeFinishesCooking;
	struct OvenQueue* queue;
};

struct Oven* ovens[OVEN_ARRAY_SIZE];

struct Oven* createOven();
void createOvens(int count);
unsigned short calculateOvenTime(struct Order* order);
void cook(struct Oven* oven, struct Order* order);
struct Oven* getFistFinishingOven();

#endif
