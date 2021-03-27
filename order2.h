#ifndef ORDER_H
#define ORDER_H

struct Order
{
	unsigned long timeReceived;
	unsigned char customerCount; // up to 255
	unsigned char largePizzaQuantity;
	unsigned char smallPizzaQuantity;
	// int pizzaQuantityByType[PIZZA_TYPES_COUNT]; // For improvement purposes. To be used when there will be more types of pizzas
};
const unsigned char queCapacity = 120;

struct Queue {
    unsigned char front, rear, size;
    struct Order* array;
};
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue();
// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, struct Order* order);
// Function to get front of queue
struct Order* front(struct Queue* queue);
// Function to get rear of queue
struct Order* rear(struct Queue* queue);

#endif