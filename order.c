#include <stdlib.h>
#include <stdio.h>
#include "order.h"

struct OrderHistory orderHistory = {0, 0};

struct Order* createOrder(unsigned short id, unsigned long timeReceived, unsigned char customerCount, unsigned char largePizzaQuantity, unsigned char smallPizzaQuantity)
{
    struct Order* order =  (struct Order*)malloc(sizeof(struct Order));
    order->id = id;
    order->timeReceived = timeReceived;
    order->customerCount = customerCount;
    order->largePizzaQuantity = largePizzaQuantity;
    order->smallPizzaQuantity = smallPizzaQuantity;

	orderHistory.orders[orderHistory.rear] = order;
    orderHistory.rear = (orderHistory.rear + 1) % ORDER_HISTORY_SIZE;
    orderHistory.size++;

    printf("Order created with id: %d for %d large and %d small pizza(s)\n", order->id, order->largePizzaQuantity, order->smallPizzaQuantity);

    return order;
}

unsigned long getTimestampB(struct Order* order)
{
	return order->timeReceived * TIMESTAMP_A / TIMESTAMP_B;
}

void printOrderStatus(unsigned long time)
{
    for(int i=0; i<orderHistory.size; i++)
    {
        struct Order* order = orderHistory.orders[i];
        if(order->timeReceived <= time && order->finishTime > time)
            printf("Order with id: %d created at %lu for %d customers for %d large and %d small pizza(s). Pizzas ready at: %lu; finishes at %lu\n", order->id, order->timeReceived, order->customerCount, order->largePizzaQuantity, order->smallPizzaQuantity, order->pizzasReadyTime, order->finishTime);
    }
}
