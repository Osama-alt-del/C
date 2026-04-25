/* This is the C for loop */

#include <stdio.h>
#include <math.h>


int main()
{
	// for (int i = 0; i<10; i++)
	// {
	// 	printf("%d\n", i);
	// }
	int year;
	double amount, principle = 1000.0, rate = 0.05;

	// Prints strings with 4 spaces and 21 spaces. With a %4d integer, it could look like: ___4 where there are 3 spaces in front
	printf( "%4s%21s\n", "Year", "Amount on deposit" );

	for ( int year = 1; year <=10; year++)
	{
		// [FIXED] For some reason it's not accepting pow. It keeps on telling me "undefined reference to 'pow'
		// I need to link the math library in the compile command. so I have to use -lm at the end of the code 
		amount = principle * pow(1+rate, year);
		// So print the year integer with 4 spaces to spare, and the amount with 21 spaces to spare, making sure it's 2 decimal places
		printf( "%4d%21.2f\n", year, amount );
	}


	return 0;
}
