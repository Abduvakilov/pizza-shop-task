#ifndef ORDER_H
#define ORDER_H
#include <stdbool.h>
#include "table.h"

#define TIMESTAMP_A 2000
#define TIMESTAMP_B 200
#define ORDER_HISTORY_SIZE 1000

struct Order
{
	unsigned short id;
	unsigned long timeReceived; // Timestamp A
	unsigned char customerCount; // up to 255
	unsigned char largePizzaQuantity;
	unsigned char smallPizzaQuantity;
	// int pizzaQuantityByType[PIZZA_TYPES_COUNT]; // For improvement purposes. To be used when there will be more types of pizzas
	unsigned long pizzasReadyTime;
	unsigned long reassignTime;
	unsigned long finishTime;
	struct Table* tableTaken;
	unsigned char tableOrderId; // records index in which the table->ordersTaken array holds the order

};
struct OrderHistory
{
	unsigned short rear;
	unsigned short size;
	struct Order* orders[ORDER_HISTORY_SIZE];
};

struct OrderHistory orderHistory;

struct Order* createOrder
(
	unsigned short id,
	unsigned long timeReceived,
	unsigned char customerCount,
	unsigned char largePizzaQuantity,
	unsigned char smallPizzaQuantity
);

unsigned long getTimestampB(struct Order* order);
void printOrderStatus(unsigned long time);

#endif
