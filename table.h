#ifndef TABLE_H
#define TABLE_H
#include <stdbool.h>

#define TABLE_ARRAY_SIZE 500
#define TABLE_ORDER_HISTORY_SIZE 120

unsigned char maxTablesCapacity;
struct Table* tables[TABLE_ARRAY_SIZE];
unsigned char tableTotal;

struct Table
{
	unsigned char capacity;
	unsigned char seatsTaken;
	struct Order* ordersTaken[TABLE_ORDER_HISTORY_SIZE]; // One table can serve more than one group of customers at a time.
	unsigned char lastOrderId;
};

// void sortTablesByCapacity(struct Table* tables);
// bool tIsFull (struct Table* table);
struct Table* getMinSeatTable(struct Order* order);
unsigned char getSeatsAvailable(struct Table* table);
struct Table* createTable(unsigned char capacity);
void takeTable(struct Table* table, struct Order* order);

#endif
