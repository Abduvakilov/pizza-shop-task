#ifndef ORDER_H
#define ORDER_H
#include <stdbool.h>
#include "table.h"

struct Order
{
	unsigned long timeReceived;
	unsigned char customerCount; // up to 255
	unsigned char largePizzaQuantity;
	unsigned char smallPizzaQuantity;
	// int pizzaQuantityByType[PIZZA_TYPES_COUNT]; // For improvement purposes. To be used when there will be more types of pizzas
	unsigned long startEatingTime;
	struct Table* tableTaken;
	unsigned char tableOrderId;
};

// struct Order* qPeek();
// bool qIsEmpty();
// bool qIsFull();
// int qSize();
// void enqueue(struct Order* order);
// struct Order* dequeue();
// void finishOrder(struct Table* table, struct Order* order);

#endif
