/* これはマージソートのファイルです。*/

// よくわからないけど、とりあえず書きます：　（本から）

// どうしたらバッファーのリストを関数内に作れるんだろう？


void mergeSort(int* array, int size){
    int i, j, k, m;
    if (size <= 1) return;

    half = size/2;

    /* ブロックを前半と後半に分ける*/
    mergeSort(array, half);
    mergeSort(array+half, size-half); // リストを [array+n] にすると、最初の値がnのところになる

    /*合併操作： */
    for(i = 0; i < m; i++) buffer[i] = array[i]
}

