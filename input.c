#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "table.h"
#include "oven.h"

#define ARG_PER_LINE 5
#define ARG_SIZE 15

void orderFromInput(unsigned long lineArgs[])
{
    struct Order* order = createOrder(lineArgs[0], lineArgs[1], lineArgs[2], lineArgs[3], lineArgs[4]);
    enqueueOrder(order);
}

struct LineArgs
{
    unsigned short lineNumber;
    unsigned char argNumber;
    unsigned char lastArgLen;
    char lastArg[ARG_SIZE];
    unsigned long lineArgs[ARG_PER_LINE];
};

int inputByChar(char x, struct LineArgs* la)
{
    if(x=='\n' || x==',')
    {
        la->lineArgs[la->argNumber] = atoi(la->lastArg);
        ++la->argNumber;
        memset(la->lastArg, 0, ARG_SIZE);
        la->lastArgLen = 0;
    }
    else
    {
        la->lastArg[la->lastArgLen] = x;
        ++la->lastArgLen;
    }
    if(strcmp(la->lastArg,"END")==0)
        return 1;

    if(x=='\n')
    {
        printf("%s\n", la->lastArg);    
        ++la->lineNumber;
        la->argNumber = 0;
        orderFromInput(la->lineArgs);
    }
    return 0;
}

void readFileAndOrder(FILE* file, bool readFirstLine)
{
    char x;
    struct LineArgs* la = &(struct LineArgs) {1, 0, 0};

    if(!readFirstLine)
    {
        while  ((x = fgetc(file)) != '\n') // Brief description
            printf("%c", x);
        printf("\n");
    }

    while  ((x = fgetc(file)) != EOF)
    {
        printf("%c", x);

        if(inputByChar(x, la) == 1)
            break;
    }
}

void readInputAndOrder()
{
    while(true)
    {
        char inputLine[255];
        fgets(inputLine,255,stdin);
        if(strcmp(inputLine,"END\n")==0 || strcmp(inputLine,"end\n")==0)
            break;

        struct LineArgs* la = &(struct LineArgs) {1, 0, 0};

        for(int i=0; i<strlen(inputLine); i++)
        {
            char x = inputLine[i];
            inputByChar(x, la);
        }
    }
}



