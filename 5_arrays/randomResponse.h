/* This is my first C header file that I will use to write a function that creates a random n number of responses for me and returns them */

#include <stdlib.h>
#include <time.h>

// Since we can't seem to return arrays using functions, it might be better to just give the memory location of the array and change it
// Added max to this function to make it more usable all around
void randResponse(int n, int array[], int max)
{
	srand(time( NULL ));

	for (int i = 0; i < n; i++)
	{
		array[i] = 1 + rand() % max;
	}

}
