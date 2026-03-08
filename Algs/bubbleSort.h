/* This is me implementing bubble sort for like the third time (practice makes perfect) */

// start with void

// We want to swap the pointers in this case, so we take pointers as the paramaters
void swap(int* x, int* y){
    int temp;
    // value of temp becomes value x is pointing to
    temp = *x;
    // x now points to a value that y was pointing to
    *x = *y;
    // y now points to a value that x was pointing to
    *y = temp;
}

void bubbleSort(int *array, int size){
    int temp, flag, k;
    flag = 1;
    k = 0;
    while(flag){ // Repeat sending bubbles through until one goes through cleanly
        flag = 0; //reset flag so that we can check
        // send bubble:
        for (int i = 0; i < size-1-k; i++){
            // If current > next then swap
            if (array[i] > array[i+1]){
                flag = 1; // remember to set the flag here to 1 to continue the alg (or use do while)
                swap(&array[i], &array[i+1]);
            }
        }
        // This ensures that we stop checking for values at the end (by reducing the reach of the bubble)
        k++;
    }
}
