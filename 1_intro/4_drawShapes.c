/* Drawing some shapes using printf */


#include <stdio.h> 

int main()
{
	// Square
	// I can manage to change the length but how do I change the width?
	int length = 10;
	for (int i = 0; i<length; i++)
	{
		if ((i != 0) && (i != length-1))
		{
			printf("*        *");
		}
		else
		{
			printf("**********");
		}
		printf("\n");
	}
}

