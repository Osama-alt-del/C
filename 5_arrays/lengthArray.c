/* This is a C program where I'm going to try and make a function that takes an array of ints and find the length */
#include <stdio.h>
int len(int* array)
{
	int length;
	length = sizeof(*array)/sizeof(array[0]);
	printf("%ld\n", sizeof(array));
	return length;

}

