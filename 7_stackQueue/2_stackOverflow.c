// This is a file where we will cause the legendary stack overflow on purpose to better understand the stack
/*
    how to cause a stack overflow: you use more memory than what's available in the stack

    there are many ways to do this: 
*/

void fun(int);


int main() { 
    
    // matrix in the main
    // int mat[1000000][100000];    

    // this should recursively call infinite times and cause a stack overflow
    fun(6);
    
    return 0;
}

// non-terminating function that will cause stack overflow:
void fun(int x) {
    fun(x); // just this is enough to cause an overflow, because eventually the memory that is available int he stack will be overflowed
}






