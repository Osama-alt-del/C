/* This is a C code that takes an array with a bunch of values and then prints stars for the magnitude of each value */

#include "randomResponse.h"
#include <stdio.h>
#define SIZE 10

int main ()
{
	int array[SIZE];
	randResponse(SIZE, array, 20);

	printf("%s%13s%17s", "Element", "Value", "Histogram\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%7d%13d       ", i, array[i]);
		
		for (int j = 0; j < array[i]; j++)
		{
			printf("*");
		}
	
		printf("\n");
	}

	return 0;
}
