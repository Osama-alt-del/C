/* This is a C file where I look at rands properies a little bit deeper and  work with it's seed a little 


So we ask the user to input the seed and then based on that the output of the rand function will change. The reason that the rand function
works this way is so that it's easier to debug

We can completely randomize the entry by using time srand(time(NULL))
time(NULL) returns the current time of the day in seconds. By using Null, we disable the function where time can return a string to show the
current time in seconds, from 1970
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int seed;
	// printf("Enter the seed: ");
	// We use u, not d for unsigned int. Since srand takes an unsigned integer, we have to use this.
	// scanf("%u", &seed);
	printf("The seed is: %ld\n", time(NULL));
	srand(time(NULL));
		for (int i = 1; i <= 20; i++)
		{
			printf("%10d", rand() %6 +1);

			if (i % 5 == 0) printf("\n");
		}
		return 0;
}
