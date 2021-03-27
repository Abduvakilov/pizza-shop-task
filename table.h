#ifndef TABLE_H
#define TABLE_H
#include <stdbool.h>

unsigned char maxTablesCapacity;

struct Table
{
	unsigned char capacity;
	unsigned char seatsTaken;
	struct Order* ordersTaken[120]; // One table can serve more than one group of customers at a time.
	unsigned char lastOrderId;
};

// void sortTablesByCapacity(struct Table* tables);
bool tIsFull (struct Table* table);
unsigned char getSeatsAvailable(struct Table*);
struct Table* createTable(unsigned char capacity);
void takeTable(struct Table* table, struct Order* order);

#endif
