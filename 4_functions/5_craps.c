/* This is C program where I will make the game "crap" */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	/*[I CAN] I wonder if I can declare all of these together in one line */
	int rollDice(), count, number, point, currentTime;
	count = 0;
	// int number;
	// int point;
	// int currentTime; /* Used to make sure that 1 second passes and the seed is different */
	while (1)
	{
		if (count == 0)	/*最初の投げ手*/
		{
			number = rollDice();
			if ((number == 7) || (number == 11))
			{
				printf("Player wins!\n");
				break;
			}
			if ((number == 2) || (number == 12) || (number == 3))
			{
				printf("Player loses\n");
				break;
			}
			point = number; 	/* Only make the point equal to the number if they didn't win or lose the game */
			printf("The point is %d\n", point);
		}
		else /* For the other state of the game, keep throwing until you get 7 or point */
		{
			if (count == 1)  /* set currentTime to the currentTime if the 'series of rolls' starts */
			{	
				currentTime = time(NULL);
			}
			if (currentTime == time(NULL)-1) /* Do not allow any dice rolls to occur until 1 second has passed */
			{
				number = rollDice(); 
				if (number == 7)
				{
					printf("Player loses\n");
					break;
				}
				else if (number == point)
				{
					printf("Player wins\n");
					break;
				}
				currentTime = time(NULL);  /* Reset the time for next delay */
			}
		}
		
		count++;
	}


	return 0;
}

int rollDice()
{
	int roll1, roll2, sum;
	srand(time(NULL));	/* Making the seed random. But it will only change every second, making the user always win the point*/
				/* You don't have to set srand every single time though, only at the start, if I didn't do this, I 
					would not have come up with the 1 second delay code though, so I guess it's ok */
	roll1 = 1+rand()%6;	/* Scale to 6 (%6) and then shift by 1 (because it's 0 - 5 normally) */
	roll2 = 1+rand()%6;
	sum = roll1 + roll2;
	printf("Player rolled, %d + %d = %d\n", roll1, roll2, sum);
	return sum;
}
