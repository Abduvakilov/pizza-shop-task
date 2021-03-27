#include <stdlib.h>
#include "table.h"
#include "order.h"

unsigned char maxTablesCapacity = 1;
unsigned char tablesCount = 0;

struct Table* createTable(unsigned char capacity)
{
	struct Table* table = (struct Table*)malloc(
        sizeof(struct Table));
	table->capacity = capacity;
	table->seatsTaken = 0;
	table->lastOrderId = -1;

	maxTablesCapacity = maxTablesCapacity < capacity ? capacity : maxTablesCapacity;
	tablesCount++;

	return table;
}

bool tIsFull (struct Table* table)
{
	return table->seatsTaken == table->capacity;
}

unsigned char getSeatsAvailable(struct Table* table)
{
	return table->capacity - table->seatsTaken;
}

struct Table* findMinSeatsTableFor(struct Order* order, struct Table* tables[])
{
	unsigned char minSeatDiff = maxTablesCapacity;
	struct Table* rTable;
	for(int i=0; i < tablesCount; i++)
	{
		struct Table* table = tables[i];
		int seatsAvailable = getSeatsAvailable(table);
		if(seatsAvailable < order->customerCount)
			continue;
		if(seatsAvailable == order->customerCount)
			return table;
		int seatDiff = seatsAvailable - order->customerCount;
		minSeatDiff = minSeatDiff > seatDiff ? seatDiff : minSeatDiff;
		rTable = table;
	}
	return rTable;
}

void takeTable(struct Table* table, struct Order* order)
{
	if(tIsFull(table))
		return;
    table->lastOrderId = (table->lastOrderId + 1)
              % table->capacity;
	table->ordersTaken[table->lastOrderId] = order;
	table->seatsTaken = table->seatsTaken + order->customerCount;
	order->tableOrderId = table->lastOrderId;
}
