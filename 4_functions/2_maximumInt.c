/* This is a C program where I find the maximum integer of a series of inputted numbers and then return and print the largest one*/


#include <stdio.h>

int maximum(int, int, int);

int main() 
{
	int a, b, c;
	printf("Enter the 3 numbers: \n");
	scanf("%d%d%d", &a, &b, &c);
	printf("The maximum is %d\n", maximum(a, b, c)); 


	return 0;
}

int maximum(int x, int y, int z)
{
	int max;
	max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	return max;
}
