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
    return order;
}