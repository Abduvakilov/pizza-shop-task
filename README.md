The program is written in C taking efficiency in mind, without any dependencies or libraries.
You need gcc to build
Build instructions:
```
cd pizza_shop
gcc main.c order.c table.c oven.c input.c -o pizza
```

The program is self explanatory.
You can run the program as:
```
./pizza
```
The output will be something similar to this:
```
1 ovens and 11 tables


Enter order details in the following format
Request Index, Issue time, Number of customers in the request, Number of large pizzas, Number of small pizzas
One order per line
Enter END to finish


Type the following line for help:
./pizza -h
Usage: ./pizza [filename -r -o N -t S N]
	filename.txt: file directory - the file that contains order list
	-r: Reads first line for order details. Off by default.
	-o N: Creates Ovens in N quantities, 1 by default.
	-t S N: Creates Table in S size and N count.
	default: { One table for 8; One table for 20; Four tables, each for 4; Five tables, each for 1 }.
```

You can manually type requests if you don’t provide filename.
To read the file from the task, run:
```
./pizza Mission0.txt
```
or
```
./pizza Mission0.txt -o 4
```
The `-o 4` argument creates 4 ovens. You can also specify tables with `-t` argument.
```
./pizza Mission1.txt -o 6 -t 3 5
```
The above command reads from `Mission1.txt` creates 4 ovens and add 5 tables for 3.
You can see it in the first 3 lines after the command
```
Table argument: 3 5
4 ovens and 16 tables
Reading file Mission1.txt
```

After the file have been read you can write simulation command to get statuses of requests, ovens, tables. Just write the keyword in plural and the timestamp you wand the data for as following
```
requests 100
tables 20
ovens 50
```
You can exit the program with control + c or entering END and pressing Enter
