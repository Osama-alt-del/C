// This is a C program with a function that returns a string

#include <stdio.h>

char* returnString();

int main(){
    printf("%s\n", returnString());

    return 0;
}



// I don't get it, we can just return string1, why do we need to do static and memory allocation and stuff?
// And why do we have to do const in the function definition?? I need to watch a video on this stuff
char* returnString(){
   char* string1 = "Hi, Hi";

   return string1; 
}
