/* This is a C program, where I will declare an array for the first time in a while!*/


#include <stdio.h>




int main()
{
	// You must specify the type of element and the number of elements required by each array so that the computer may reserve memory
	int c[12];

	// You can also declare multiple arrays in the same line:
	int a[50], b[90];

        // --------------Using a variable for it ---------------------//:

        int length = 3;
        // you cannot do this:
        int array1[length] = {1, 2, 3};

        // But you can do this:
        int array2[length];

        // You can, however, do the following: (define them later)
        int array1[length];
        array1[0] = '1';
        array1[2] = '2';
        array1[3] = '3';

	return 0;
}



