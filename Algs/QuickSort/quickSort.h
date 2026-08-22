// This is quickSort

void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function (returns the position that pivot should be in)
int partition(int* array, int low, int high){
    // Swap all of the values less the pivot and greater than the pivot until you find the index
    int i, j, pivot;
    i = low;
    j = high;
    pivot = array[low];
    do{
        do{i++;}while(array[i] <= pivot); // find a value greater than the pivot
        do{j--;}while(array[j] > pivot); // find a value greater than the pivot
        if (i < j){ // If still finding position of pivot:
            swap(&array[i], &array[j]);
        }
    }while(i < j);
    // swap once you've found the position of the pivot
    swap(&array[j], &array[low]);
    return j;
}

// quickSort:
void quickSort(int* array, int low, int high){
    if (low < high){
        // Find the position that the array should be in
        int j = partition(array, low, high);
        quickSort(array, low, j);
        quickSort(array, j+1, high);
    }
}
