/* This is a program that I'm using to separate a number using C  */

#include <stdio.h>

int main(){
	// So we are going to assume it's a 5 digit at the start
	int integer, a1, a2, a3, a4, a5;
	printf("Enter the number: ");
	scanf("%d", &integer);
	a5 = integer%10;
	integer = integer/10;
	a4 = integer%10;
	integer = integer/10;
	a3 = integer%10;
	integer = integer/10;
	a2 = integer%10;
	integer = integer/10;
	a1 = integer%10;
	integer = integer/10;
	printf("%d %d %d %d %d \n", a1, a2, a3, a4, a5);
	return 0;
}

