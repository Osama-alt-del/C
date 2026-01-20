/* This file will be used to show how we can set and print the values of an array in C */
#include <stdio.h>


int main()
{
	// This is one way to initialize the values in an array
	int b[5] = {1, 2, 3, 4, 5};
	int c[5] = {2}; /* By not specifying the the rest of the values in an array, they are automatically set to zero */
	int d[] = {1, 2, 3, 4, 5, 6}; /* By not specifying the number of elements in the array, the number of elements taken from the intializer list */

	for (int i = 0; i<5; i++)
	{
		printf("%2d%3d%3d\n", i, b[i], c[i]);
	}

	printf("\n");


	for (int i = 0; i < 6; i++)
	{
		printf("%2d%2d\n", i, d[i]); /* It prints out with no problem even though we didn't specify the # of values */
	}



	return 0;
}
