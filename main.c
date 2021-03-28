#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "table.h"
#include "oven.h"

#define ARG_PER_LINE 5
#define ARG_SIZE 15

int main(int argc, char *argv[])
{
	if((argc==2 && strcmp(argv[1], "-h")==0) || argc == 1)
	{
		printf("Usage: %s filename [-s -1]\n", argv[0]);
		printf("	filename.txt: file directory - the file that contains order list\n");
		printf("	-s: Turns Simulation mode on.\n");
		printf("	-1: Reads first line for order details. Off by default.\n");
		return 0;
	}
	bool simulationMode = false;
	bool readFirstLine = false;
	if(argc==3)
	{
		if(strcmp(argv[2],"-s")==0)
			simulationMode = true;
		if(strcmp(argv[2],"-1")==0)
			readFirstLine = true;
	}
	else if (argc==4)
	{
		if(strcmp(argv[2],"-s")==0 || strcmp(argv[3],"-s")==0)
			simulationMode = true;
		if(strcmp(argv[2],"-1")==0 || strcmp(argv[3],"-1")==0)
			readFirstLine = true;
	}
	// Command line arguments end

	createTable(4);
	createTable(4);
	createTable(8);
	createTable(8);

	createOvens(3);

	printf("%d ovens and %d tables\n", ovenCount, tableCount);
	// Table and Oven initialization end

	FILE* file = fopen( argv[1], "r" );

	if ( file == 0 )
	{
		printf( "Could not open file\n" );
		return 1;
	}
    char x;
    printf("Reading file %s\n", argv[1]);
    char lastArg[ARG_SIZE];
    int lineArgs[ARG_PER_LINE];
    unsigned short lineNumber = 1;
    unsigned char argNumber = 0;
    unsigned char lastArgLen = 0;

    if(!readFirstLine)
    {
    	while  ((x = fgetc(file)) != '\n') // Brief description
    		printf("%c", x);
	    printf("\n");
	}

    while  ((x = fgetc(file)) != EOF)
    {
        printf("%c", x);

		if(x=='\n' || x==',')
		{
			lineArgs[argNumber] = atoi(lastArg);
			argNumber++;
			memset(lastArg, 0, ARG_SIZE);
			lastArgLen = 0;
		}
		else
		{
			lastArg[lastArgLen] = x;
			lastArgLen++;
		}

        if(strcmp(lastArg,"END")==0)
        	break;
        if(x=='\n')
        {
        	lineNumber++;
        	argNumber = 0;
        	struct Order* order = createOrder(lineArgs[0], lineArgs[1], lineArgs[2], lineArgs[3], lineArgs[4]);
		    printf("order created with id: %d for %d large and %d small pizza(s)", order->id, order->largePizzaQuantity, order->smallPizzaQuantity);
        	enqueueOrder(order);
        }
    }
    fclose(file);

	return 0;
}