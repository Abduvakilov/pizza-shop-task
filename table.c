#include <stdlib.h>
#include <stdio.h>
#include "table.h"
#include "order.h"

unsigned char maxTablesCapacity = 1;
unsigned char tableTotal = 0;

struct Table* createTable(unsigned char capacity)
{
	struct Table* table = (struct Table*)malloc(sizeof(struct Table));
	table->capacity = capacity;
	table->totalOrders = 0;

	maxTablesCapacity = maxTablesCapacity < capacity ? capacity : maxTablesCapacity;
	tables[tableTotal] = table;
	tableTotal++;

	return table;
}

unsigned char getSeatsLeft(struct Table* table, unsigned long time)
{
	struct Order* orders = *(table->orderList);
	int customers = 0;
	printf("Table total orders %d\n", table->totalOrders);
	for(int i=0; i<(table->totalOrders); i++)
	{
		if(orders[i].timeReceived <= time)
		{
			customers += orders[i].customerCount;
			printf("%d\n", orders[i].customerCount);
		}
		if(orders[i].finishTime <= time)
		{
			customers -= orders[i].customerCount;
			printf("%d\n", orders[i].customerCount);
		}
	}
	return table->capacity - customers;
}

bool tIsFull (struct Table* table, unsigned long time)
{
	return getSeatsLeft(table, time) == 0;
}

struct Table* getMinSeatTable(struct Order* order)
{
	unsigned char minSeatDiff = maxTablesCapacity;
	struct Table* rTable;
	for(int i=0; i < tableTotal; i++)
	{
		struct Table* table = tables[i];
		unsigned char seatsLeft = getSeatsLeft(table, order->timeReceived);
		if(seatsLeft < order->customerCount)
			continue;
		if(seatsLeft == order->customerCount)
			return table;
		int seatDiff = seatsLeft - order->customerCount;
		if(minSeatDiff > seatDiff)
		{
			minSeatDiff = seatDiff;
			rTable = table;			
		}
	}
	return rTable;
}

void takeTable(struct Table* table, struct Order* order)
{
	unsigned long time = order->timeReceived;
	if(tIsFull(table, time))
		return;
	table->orderList[table->totalOrders] = order;
    table->totalOrders = (table->totalOrders + 1) % TABLE_ARRAY_SIZE;
	order->tableOrderId = table->totalOrders;
	printf("%d customer(s) sit on %d place table\n", order->customerCount, table->capacity);
}

void printTablesStatus(unsigned long time)
{
	for(int i=0; i<tableTotal; i++)
	{
		struct Table* table = tables[i];
		unsigned char seatsLeft = getSeatsLeft(table, time);
		printf("Table %d: capacity %d; seats left %d.\n", i, table->capacity, seatsLeft);
	}
}
