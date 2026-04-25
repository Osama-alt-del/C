#include <math.h>
#include <stdio.h>

int getValue(int, int);

int main() {

    int x = 12345678;

    printf("%d\n", getValue(x, 1));
    printf("%d\n", getValue(x, 2));
    printf("%d\n", getValue(x, 3));
    printf("%d\n", getValue(x, 4));
    printf("%d\n", getValue(x, 5));



    return 0;
}

int getValue(int x, int i) {
    if (i>=1) {
        return (x % (int)pow(10, i)/ (int)pow(10, i-1));    
    } else {
        return 0;
    }
}
