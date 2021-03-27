#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "order.h"
#include "table.h"

// struct Order* queue[QUEUE_ARRAY_SIZE];
// unsigned char qFront = 0;
// unsigned char qRear = -1;
// unsigned char qItemCount = 0;

// struct Order* qPeek()
// {
//    return queue[qFront];
// }

// bool qIsEmpty()
// {
//    return qItemCount == 0;
// }

// bool qIsFull()
// {
//    return qItemCount == QUEUE_ARRAY_SIZE;
// }

// int qSize()
// {
//    return qItemCount;
// }

// void enqueue(struct Order* order)
// {

//    if(maxTablesCapacity < order->customerCount)
//    {
//       printf("Cannot add. Too many customers\n");
//       return;
//    }

//    if(qIsFull())
//    {
//       printf("Cannot add. Queue is full\n");
//       return;
//    }

//    if(qRear == QUEUE_ARRAY_SIZE-1)
//    {
//       printf("Queue array starting over\n");
//       qRear = -1;            
//    }

//    printf("Adding order to queue\n");
//    queue[++qRear] = order;
//    qItemCount++;
// }

// struct Order* dequeue()
// {
//    struct Order* order = queue[qFront++];
	
//    if(qFront == QUEUE_ARRAY_SIZE) {
//       qFront = 0;
//    }
	
//    qItemCount--;
//    return order;  
// }

// void finishOrder(struct Table* table, struct Order* order)
// {
//    if(table->ordersTaken[order->tableOrderId] != order)
//       return;
//    table->seatsTaken = table->seatsTaken - order->customerCount;
// }
