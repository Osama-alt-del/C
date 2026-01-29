/* This is a C program where I will try to reverse a string  */

#include <stdio.h>
#include <string.h>
#define MAXLIMIT 999/* This is our maximum limit for the input string */
int main()
{
char str1[MAXLIMIT];
printf("Enter the string you would like to reverse:  ");
scanf("%s", &str1);
int length = strlen(str1);
// Can use a variable in the square brackets for the element size (compile time constant), but we can't say what's inside it 
char str2[strlen(str1)]; /* If we don't do {0} then we will get junk values */

for (int i = length-1; i > -1; i--)
{
	// printf("%d  %d\n", i, length-i-1);
	str2[i] = str1[length-1-i];
}


printf("%s\n", str2);



return 0;
}
