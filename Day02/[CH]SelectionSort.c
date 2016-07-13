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
#define SORTNAME "선택정렬"

void SelectionSort(int *p, const int size);
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
    
    SelectionSort(arr, size); 
    printArr(arr, size);
    
    printf(division_line);
    println();
}

void SelectionSort(int *p, int size) {
    int i,j,tmp,index;

    for(i=0;i<size-1;i++) {
        index = i;
        for(j=i+1;j<size;j++) {
            if( p[j] < p[index] ) index = j;
        }
        tmp = p[index];
        p[index] = p[i];
        p[i] = tmp;
    }
}

void printArr(int *p, const int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
}
