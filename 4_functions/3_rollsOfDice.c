/* This is a C program where I will simulate and print out 20 rolls of 6 sided dice 
By writing 'rand() % num + 1' we get a random number in between 0 and num
This can be summarized as n = a + rand() % b; where b is the width, and a is the start
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int face, n1, n2, n3, n4, n5, n6;
	n1 = n2 = n3 = n4 = n5 = n6 = 0;
	for (int i = 1; i <= 6000; i++)
	{
		face = rand() %6 +1;
		printf("%10d", face);

		if (i % 5 == 0) printf("\n");

		switch( face )
		{
			case 1:		/* Adds to frequency for each number based on the value*/
				n1++;
				break;
			case 2:
				n2++;
				break;
			case 3:
				n3++;
				break;
			case 4:
				n4++;
				break;
			case 5:
				n5++;
				break;
			case 6:
				n6++;
				break;
			default:	/* If it's none of the above */
				break;
		}
	}

	printf("Number of 1s: %d\n", n1);
	printf("Number of 2s: %d\n", n2);
	printf("Number of 3s: %d\n", n3);
	printf("Number of 4s: %d\n", n4);
	printf("Number of 5s: %d\n", n5);
	printf("Number of 6s: %d\n", n6);

	return 0;
}
