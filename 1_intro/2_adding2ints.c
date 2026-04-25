/* Adding two integers

*/

#include <stdio.h>

int main()
{
	// This is called a declaration
	int integer1, integer2, sum;
	printf("Enter first integer \n");
	// Take the integer inputed and store into the address of int1 (d means decimal integer)
	scanf("%d", &integer1);
	printf("Enter second integer \n");
	scanf("%d", &integer2);
	sum = integer1 + integer2;
	printf("The sum is %d\n", sum);
}
