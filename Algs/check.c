// Just going to check something to do with arrays here
#include <stdio.h>

int main(){
    int length = 5;
    int array[length];

    for (int i = 0; i < length; i++){
        array[i] = i;
    }

    // Print the array:
    for (int i = 0; i < length; i++){
        printf("%d\n", array[i]);
    }

}
