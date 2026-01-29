/* This is a file that I will use to look at the malloc and calloc functions in C */

#include <stdio.h>
#include <stdlib.h>

int len(int*);


int main()
{
// First I want to make a dynamically sized object:
int array1[]  = {1, 2, 3};
printf("%d", len(array1));
int array2[len(array1)]; /* This gives me the error "variable sized object may not be initialized (but we can declare it)*/
// So these functions return pointers to the allocated memory that they change, meaning tha tI can say "array2 = calloc
array2 = calloc(len(array1), sizeof(int));
return 0;
}


int len(int array[])
{
	int length;
	length = sizeof(array)/sizeof(array[0]);
	return length;
}
