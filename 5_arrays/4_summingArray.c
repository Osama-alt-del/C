/* This is a C file where I will sum the values of an array */

#include <stdio.h>
#define SIZE 12

int main()
{
	int a [ SIZE ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, total = 0;

	for (int i = 0; i < SIZE; i++)
	{
		total += a[i];
	}

	printf("The total is: %d\n", total);

	return 0;
}
