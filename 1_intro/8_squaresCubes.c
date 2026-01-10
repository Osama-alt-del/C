/* This is a C program where I take a number and then print the square and the Cube of the number
*/
#include <stdio.h>

int main()
{
	printf("number	square	cube\n");
	for (int i = 0; i < 11; i++)
	{
		// We can also use pow() from the <math.h> library
		printf("%d	%d	%d\n", i, i*i, i*i*i);
	}
	return 0;
}
