/* This is my first C header file that I will use to write a function that creates a random n number of responses for me and returns them */

#include <stdlib.h>

// Since we can't seem to return arrays using functions, it might be better to just give the memory location of the array and change it
void randResponse(int n, int array[])
{

	for (int i = 0; i < n; i++)
	{
		array[i] = 1 + rand() % 10;
	}

}
