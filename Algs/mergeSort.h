/* これはマージソートのファイルです。*/

void mergeSort(int* array, int size){
    int i, j, k, mid;
    int buffer[size];  /*｛｝を使わないなら、変数を使っても良い*/
    if (size <= 1) return; /*一個のものでしかない場合、リターンする */

    mid = size/2;

    /* ブロックを前半と後半に分ける*/
    mergeSort(array, mid);
    mergeSort(array+mid, size-mid); // リストを [array+n] にすると、最初の値がインデックスnで始まる

    /*合併操作： */
    for(i = 0; i < mid; i++) buffer[i] = array[i]; /* バッファのリストをどう定義すればいいんだろう */

    j = mid;
    i = k = 0;
    while(i < mid && j < size) {
        if (buffer[i] <= array[j]){
            array[k++] = buffer[i++];
        } else {
            array[k++] = array[j++];
        }
    }
    while(i < mid) array[k++] = buffer[i++];
}

