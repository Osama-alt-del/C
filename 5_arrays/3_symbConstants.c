/* This is a C file where I will use a symbolic constant to make defining an array scalable 
This file simply takes the SIZE and then creates an array with SIZE number of even elements and 
then prints those out
*/

#include <stdio.h>
#define SIZE 10


int main()
{
	int array[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		array[i] = 2+2*i;	
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d%4d\n", i, array[i]);	
	}

	return 0;
}
