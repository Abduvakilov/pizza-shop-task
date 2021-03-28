#ifndef TABLE_H
#define TABLE_H
#include <stdbool.h>

#define TABLE_ARRAY_SIZE 500
#define TABLE_ORDER_HISTORY_SIZE 500

unsigned char maxTablesCapacity;
struct Table* tables[TABLE_ARRAY_SIZE];
unsigned char tableTotal;

struct Table
{
	unsigned char capacity;
	struct Order* orderList[TABLE_ORDER_HISTORY_SIZE]; // One table can serve more than one group of customers at a time.
	unsigned short totalOrders;
};

// void sortTablesByCapacity(struct Table* tables);
// bool tIsFull (struct Table* table);
struct Table* getMinSeatTable(struct Order* order);
// unsigned char getSeatsAvailable(struct Table* table, unsigned long time);
struct Table* createTable(unsigned char capacity);
void takeTable(struct Table* table, struct Order* order);
void printTablesStatus(unsigned long time);

#endif
