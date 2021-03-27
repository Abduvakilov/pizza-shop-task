#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "table.h"
#include "oven.h"

int main(int argc, char *argv[])
{
	if((argc==2 && strcmp(argv[1], "-h")==0) || argc == 1)
	{
		printf("Usage: filename.txt [simulation]\n");
		printf("filename.txt: file directory - the file that contains order list\n");
		printf("simulation: 1 or 0 - Turns Simulation mode. optional value, 0 by default\n");
		return 0;
	}

	struct Table* tables[] = {
		createTable(4),
		createTable(4),
		createTable(8),
		createTable(8),
	};
	struct Order orders[] = {
		{30,1,2,1},
		{30,1,2,1},
		{30,1,2,1}
	};

	createOvens(3);
	printf("%d\n", ovensCount);
	for(int i=0;i<3;i++)
	{
		enqueueOrder(&orders[i]);
	}
	return 0;
}