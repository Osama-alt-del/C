/* This is a C program where I play around with C strings, chars and arrays to understand them better */

/* Every string has a special string termination chararcter called the null character. it is represented by '\0'. */

#include <stdio.h>
#include <string.h> /* There are some nice functions to deal with strings here */

int main()
{

	char str1[] = "Hello Again World"; /* Strings are just character arrays */
	printf("%s\n", str1);

	printf("%ld\n", strlen(str1));	/* We can use strlen to get the length of the string */
	
	for (int i = 0; i < strlen(str1); i++) /* This for loop also prints out the string, showing that it's an array of chars */
	{
		printf("%c", str1[i]);
	}

	printf("\n");

	char str2[] = "123";
	printf("%ld\n", strlen(str2)); /* Strlen will return the number of characters in the string, but not the null character */

	for (int i = 0; i < strlen(str1); i++) 
	{
		printf("%c ", str1[i]);
	}

	printf("\n");

	return 0;
}
