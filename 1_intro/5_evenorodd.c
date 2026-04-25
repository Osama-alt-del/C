/* This is a program to tell if a number is even or odd */
#include <stdio.h>

int main()
{
	// Take input:
	int integer;
	printf("Enter the number: \n");
	scanf("%d", &integer);

	// Condition:
	if (integer % 2 == 0)
	{
		printf("This number is even \n");
	}
	else
	{
		printf("This number is odd \n");
	}
	return 0;
}
