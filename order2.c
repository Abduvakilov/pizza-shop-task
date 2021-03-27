#include <stddef.h>
#include <stdlib.h>
#include "order.h"
#include "pizza.h"


struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = queCapacity - 1;
    queue->array = (struct Order*)malloc(
        queCapacity * sizeof(struct Order));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queCapacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, struct Order* order)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queCapacity;
    queue->array[queue->rear] = order;
    queue->size = queue->size + 1;
}
 
struct Order* dequeue(struct Queue* queue)
{
    struct Order* order = &queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queCapacity;
    queue->size = queue->size - 1;
    return order;
}
 
// Function to get front of queue
struct Order* front(struct Queue* queue)
{
    return &queue->array[queue->front];
}
 
// Function to get rear of queue
struct Order* rear(struct Queue* queue)
{
    return &queue->array[queue->rear];
}
