/* This is a program where we count the letter grades */


#include <stdio.h>


int main()
{
	// We can make this an integer. Chars are 1 byte and so are integers
	int grade;
	int aCount = 0, bCount = 0, cCount = 0, dCount = 0, eCount = 0, fCount = 0;

	printf("Enter the letter grades. \n");
	printf("Enter the EOF character to end input. \n");
	
	// The EOF character differs between operating systems. For linux, it's ctr+D (or at least for me it is)
	while ( ( grade = getchar() ) != EOF )
	{
		switch (grade)
		{
			case 'A':case'a':
				aCount++;
				break;
			case 'B':case'b':
				bCount++;
				break;
			case 'C':case'c':
				cCount++;
				break;
			case 'D':case'd':
				dCount++;
				break;
			case 'E':case'e':
				eCount++;
				break;
			case 'F':case'f':
				fCount++;
				break;
			case '\n':case ' ': // Ignore this input
				break;
			default: // All other characters
				printf("Incorrect letter grade entered.");
				printf("Enter a new grade.\n");
		}

	}
	printf("\nThe totals for each letter grade are:\n");
	printf("A grade: %d\n", aCount);
	printf("B grade: %d\n", bCount);
	printf("C grade: %d\n", cCount);
	printf("D grade: %d\n", dCount);
	printf("E grade: %d\n", eCount);
	printf("F grade: %d\n", fCount);

	return 0;
}
