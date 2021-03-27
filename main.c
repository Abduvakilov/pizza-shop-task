#include <stdio.h>
#include <stdlib.h>
#include "order.h"
#include "table.h"
#include "oven.h"

int main()
{
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
		struct Oven* oven = getFistFinishingOven();
		cook(oven, &orders[i]);
	}
	return 0;
}