/*
* 2016-07-12
* 퀵정렬
* ShellSort.c
* Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "퀵정렬"

void QuickSort(int *p, int left, int right);
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

    QuickSort(arr, 0, size-1);
    printArr(arr, size);
    
    printf(division_line);
    println();
    
    return 0;
}

void QuickSort(int *p, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = p[(left + right) / 2];
    
    while(i <= j) {
        while(p[i] < pivot)
            i++;
        while(p[j] > pivot)
            j--;
        if(i <= j) {
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
            i++;
            j--;
        }    
    }

    if(left < j)
        QuickSort(p, left, j);
    if(i < right)
        QuickSort(p, i, right);
}

void printArr(int *p, const int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    println();
}
