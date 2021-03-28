#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "table.h"
#include "oven.h"
#include "input.h"

#define MAX_TABLE_SIZE 31

void printHelp(char argv0[])
{
	printf("Usage: %s [filename -r -o N -t S N]\n", argv0);
	printf("	filename.txt: file directory - the file that contains order list\n");
	printf("	-r: Reads first line for order details. Off by default.\n");
	printf("	-o N: Creates Ovens in N quantities, 1 by default.\n");
	printf("	-t S N: Creates Table in S size and N count.\n");
	printf("	default: { One table for 8; One table for 20; Four tables, each for 4; Five tables, each for 1 }.\n");
}

void printInputHelp()
{
    printf("Enter order details in the following format\n");
    printf("Request Index, Issue time, Number of customers in the request, Number of large pizzas, Number of small pizzas\n");
    printf("One order per line\n");
    printf("Enter END to finish\n");
}

int main(int argc, char *argv[])
{
	bool simulationMode = false;
	bool readFirstLine = false;
	char filename[255];
	unsigned char tableCountArg[MAX_TABLE_SIZE] = { 0 };
	tableCountArg[8] = 1;
	tableCountArg[20] = 1;
	tableCountArg[4] = 4;
	tableCountArg[1] = 5;
	unsigned char ovenCountArg = 1;
	for(int i=1; i<argc; i++)
	{
		char arg[255];
		strcpy(arg, argv[i]);
		if(strcmp(arg, "-t") == 0)
		{
			if(argc > (i + 2))
			{
				printf("Table argument: %s %s\n", argv[i+1], argv[i+2]);
				unsigned char size = atoi(argv[i+1]);
				unsigned char count = atoi(argv[i+2]);
				tableCountArg[size] = count;
				i=i+2;
			}
			else
			{
				printHelp(argv[0]);
				return 1;
			}
			continue;
		}
		if(strcmp(arg, "-o") == 0)
		{
			if(argc>++i)
				ovenCountArg = atoi(argv[i]);
			else
			{
				printHelp(argv[0]);
				return 1;
			}
			continue;
		}
		if(strcmp(arg, "-h") == 0)
		{
			printHelp(argv[0]);
			return 1;
			continue;
		}
		if(strcmp(arg, "-r") == 0)
		{
			readFirstLine = true;
			continue;
		}
		if(simulationMode == true)
		{
			printHelp(argv[0]);
			return 1;
		}
		simulationMode = true;
		strcpy(filename, arg);
	}
	// Command line arguments end

	for(int size=1; size<=MAX_TABLE_SIZE; size++)
	{
		unsigned char count = tableCountArg[size];
		if(count>0)
			for(int j=0; j<count; j++)
				createTable(size);
	}

	createOvens(ovenCountArg);

	printf("%d ovens and %d tables\n", ovenCount, tableTotal);
	// Table and Oven initialization end

	if(simulationMode==true)
	{
    	FILE* file = fopen(filename, "r" );

	    if ( file == 0 )
	    {
	        printf( "Could not open file: %s\n", filename);
	        return 1;
	    }
	    printf("Reading file %s\n", filename);
		readFileAndOrder(file, readFirstLine);
	    fclose(file);
	    return 0;
	}

	printInputHelp();
	readInputAndOrder();

	return 0;
}