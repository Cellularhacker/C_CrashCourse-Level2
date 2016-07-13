/*
* 2016-07-07
* 선택정렬-임의의 배열크기
* Selection_Sort2.c
* Cellularhacker
*/
#include <stdio.h>
//#define SIZE 10
#include <stdlib.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "합병정렬"

void MergeSort(int *p, int size);
void MergeSort_Split(int *arr, int left, int right, int *p, int size);
void MergeSort_Merge(int *arr, int left, int mid, int right, int *p, int size);
void printArr(int *p, const int size);

int main(void) {
    int i;
    int *arr;
    unsigned int size;
    
    printf(division_line);
    printf("<"SORTNAME">\n");

    /* <-동적할당 코드 START-> */
    printf("배열의 크기 입력>> ");
    scanf("%u",&size);
    arr = (int*) malloc(sizeof(int)*size);    
    /* <-동적할당 코드 END-> */

    printf("\n[%d개 입력]>> ", size);
    
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    
    MergeSort(arr, size); 
    printArr(arr, size);
    
    printf(division_line);
    println();
}

void MergeSort(int *p, int size) {
    int i, arr[size];
    for(i=0;i<size;i++) arr[i] = p[i];
    MergeSort_Split(arr, 0, size-1, p, size);
}


void MergeSort_Split(int arr[], int left, int right, int *p, int size) {
    int mid;

    //printf("MergeSort_Split has been called!\n"); //DEBUG CODE

    //Excute this 'if' when spliting is not finished.
    if(left < right) 
        mid = (left + right)/2;
    
    MergeSort_Split(arr, left, mid, p, size); //Splits Left Block
    MergeSort_Split(arr, mid+1, right, p, size); //Splits Right Block
    printf("Calling MergeSort_Merge(); ...\n"); //DEBUG CODE
    MergeSort_Merge(arr, left, mid, right, p, size);
    
    printArr(arr, size); //DEBUG CODE
}

void MergeSort_Merge(int arr[], int left, int mid, int right, int *p, int size) {
    int i = left, j = mid + 1, k = left;
    int m;
    
    int tmp_arr[size];

    printf("MergeSort_Merge() has been called!\n"); //DEBUG CODE

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
    printArr(arr, size); //DEBUG CODE
}


void printArr(int *p, int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    printf("\n");
}
