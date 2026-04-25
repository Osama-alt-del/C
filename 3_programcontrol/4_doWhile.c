/* This is a program where I show the difference between the while loop and the do while loop */

#include <stdio.h>

int main()
{
	//　この二つのループは同じ
	int counter = 0;

	while ( counter++ < 10 )
	{
		printf("%d\n", counter);	
	}

	counter = 0;
	// 以下のコードは零から十まで表示する。
	do 
	{
		printf("%d\n", counter);	
	} while (counter++ < 10);

	return 0;
}
