/* Incremental while loop testing */

// ++x increments x and then uses the incremented value in the expression
// x++ uses the original value of x and then increments it after the expression

#include <stdio.h>


int main()
{
	int counter = 0;
	// We can increment the counter over here: (we can also do ++counter)
	while ( counter++ < 10 )
	{
		printf("%d\n", counter);
		//++counter;
	}
	return 0;
}
