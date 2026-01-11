/* This is a C code where I will make a function that will sqaure a numbber and then return the result 
(I guess we have to put the function definition at the bottom of the code) 

When I leave the function definition at the end of the code, I get the following: 

1_squared.c: In function ‘main’:
1_squared.c:14:24: warning: implicit declaration of function ‘square’ [-Wimplicit-function-declaration]
   14 |         printf("%d\n", square( number1 ));

It's just a warning in the end, but it could be a bad practice
*/

#include <stdio.h>



int main()
{
	int number1;
	printf("Enter the number to be squared: ");
	scanf("%d", &number1);

	printf("%d\n", square( number1 ));
	return 0;
}

/* Function definition */
int square(int number)
{
	return number*number;
}
