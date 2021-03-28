#ifndef ORDER_H
#define ORDER_H
#include <stdbool.h>
#include "table.h"

#define ORDER_HISTORY_SIZE 1000

struct Order
{
	unsigned short id;
	unsigned long timeReceived;
	unsigned char customerCount; // up to 255
	unsigned char largePizzaQuantity;
	unsigned char smallPizzaQuantity;
	// int pizzaQuantityByType[PIZZA_TYPES_COUNT]; // For improvement purposes. To be used when there will be more types of pizzas
	unsigned long readyTime;
	struct Table* tableTaken;
	unsigned char tableOrderId;

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

#endif
