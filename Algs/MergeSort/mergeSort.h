/* これはマージソートのファイルです。*/

// Continue to divide the array into smaller and smaller portions
// l and r define the portion of the array that we are looking at
// We are going to use the following function to merge the sorted arrays together
void mergeSortedArrays(int* array, int l, int m, int r){
    // The length of the previous portion: Although we will try to split evenly, they could be odd, so this is important:
    // The bottom is m-(L) + 1
    int left_length = m-l+1;
    int right_length = r-m;
    
    // Now we want temp arrays for sorting:
    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;
    // We want to first copy the portions of the array that we want to work with into the temp arrays
    for (int i = 0; i < left_length; i++){
        // Need to make sure that we write l+1, because the portion we are working with may not be at the start
        temp_left[i] = array[l + i];
    }
    for (int i = 0; i < right_length; i++){
        // Need to make sure that we write l+1, because the portion we are working with may not be at the start
        temp_right[i] = array[m + 1 + i];
    }

    // This is the hard part, merging the sorted subarrays:
    // We have 3 arrays: left portion, right portion, and the entire array
    // k will go to the left most index, to the right most index
    // We will fill in the current entire array (could just be a bigger portion) with either temp_right or temp_left array vals
    // i and j will track what index we are in in the left and right arrays:
    for (i = 0, j = 0, k = l; k <= r; k++){
        // This if statement is a bit tricky:
        // The first part (i < left_length) && (j >= right_length) is if we have reached the end of the second array and not the first array
        // The second part is simply a comparison
        if ((i < left_length) && (j >= right_length) || temp_left[i] <= temp_right[j]){
            array[k] = temp_left[i];
            i++;
        }
        else{
            array[k] = temp_right[j];
            j++;
        }
    }
}

void mergeSortRecursion(int* array, int l, int r){
    // We only want this to continue if l is greater than or equal to r (more than 1 value)
    if (l < r){
        // Find the middle index of the array
        int m = l + (r-l) / 2;
        
        // Now we are going to call the function again to divide with indexes defining the left and right portions:
        mergeSortRecursion(array, l, m);
        mergeSortRecursion(array, m + 1, r);
        // Then we will have the sorted portions of the array in those indexes (?) so we want to merge those:
        // (keep in mind that at the start, they are pieces of 1), and then are sorted with the bottom function:
        mergeSortedArrays(array, l, m, r);
    }
    
}


// We are going to split this into three functions
void mergeSort(int* array, int length){
    // Firstly we divide into blocks
    mergeSortRecursion(array, 0, length-1);
}

