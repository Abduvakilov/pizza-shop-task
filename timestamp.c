#include "timestamp.h"

#define TIMESTAMP_A 2000
#define TIMESTAMP_B 200

unsigned long time = 0;
unsigned long timestampA = 0;
unsigned long timestampb = 0;

unsigned long getTime()
{
	return time;
}

unsigned long getTimestampA()
{
	return getTime() / TIMESTAMP_A;
}

unsigned long getTimestampB()
{
	return getTime() / TIMESTAMP_B;
}
