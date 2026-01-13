/* This is a C file where I look at rands properies a little bit deeper and  work with it's seed a little */

#include <stdio.h>


int main()
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

return 0;
}
