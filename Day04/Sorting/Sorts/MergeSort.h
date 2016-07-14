/*
* 2016-07-14
* 파일 분리 프로젝트
* MergeSort.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef MergeSort_H
#define MergeSort_H
void MergeSort(int *p, int size, int round);
void MergeSort_Split(int arr[], int left, int right, int round);
void MergeSort_Merge(int arr[], int left, int mid, int right, int round);
#endif

#ifndef printArr_Func
#define printArr_Func
void printArr(int *p, int size);
#endif

void MergeSort(int *p, int size, int round) {
    int i, arr[size];
    for(i=0;i<size;i++) arr[i] = p[i];
    MergeSort_Split(arr, 0, size-1, p, size);
}


void MergeSort_Split(int arr[], int left, int right, int round) {
    int mid;

    //printf("MergeSort_Split has been called!\n"); //DEBUG CODE

    //Excute this 'if' when spliting is not finished.
    if(left < right) 
        mid = (left + right)/2;
    
    MergeSort_Split(arr, left, mid, round); //Splits Left Block
    MergeSort_Split(arr, mid+1, right, round); //Splits Right Block
    printf("Calling MergeSort_Merge(); ...\n"); //DEBUG CODE
    MergeSort_Merge(arr, left, mid, right, round);
    
    //printArr(arr, size); //DEBUG CODE
}

void MergeSort_Merge(int arr[], int left, int mid, int right, int round) {
    int i = left, j = mid + 1, k = left;
    int m;
    
    int tmp_arr[size];

    //printf("MergeSort_Merge() has been called!\n"); //DEBUG CODE

    //Compares Each left to mid & mid+1 to right
    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            tmp_arr[k] = arr[i];
            i++;
        }
        else {
            tmp_arr[k] = arr[j];
            j++;
        }
        k++;
    }
    
    // I D K
    if(i > mid) {
        for(m=j; m<=right; m++) {
            tmp_arr[k] = arr[m];
            k++;
        }
    }
    else {
        for(m=i; m<=mid; m++) {
            tmp_arr[k] = arr[m];
            k++;
        }
        
    }
    for(m=left;m<right;m++) {
        arr[m] = tmp_arr[m];
        p[m] = tmp_arr[m];
    }
    //printArr(arr, size); //DEBUG CODE
}

void printArr(int *p, int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    printf("\n");
}