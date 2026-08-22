
#include <stdio.h>
struct Hello { 
    int x;
    int y;
};


int main() { 
    struct Hello hello;
    hello.x = 5;
    printf("%d", hello.x);

    
    return 0;
}

