/*
* 2016-07-12
* 버블정렬
* BubbleSort.c
* Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "버블정렬"

void BubbleSort(int *p, int size);
void printArr(int *p, int size);

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
 
    printf("%d개의 정수 입력>> ",size);

    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

    BubbleSort(arr, size);   
    printArr(arr, size);
    
    printf(division_line);
    println();

    return 0;
}

void BubbleSort(int *p, int size) {
    int i, tmp;
    for(i=0;i<size-1;i++) {
        if(p[i] > p[i+1]) {  //오름차순: >, 내림차순: <
            tmp = p[i];
            p[i] = p[i+1];
            p[i+1] = tmp;
        }
    }
}

void printArr(int *p, int size) {
    int i;

    printf("Result: ");
    for(i=0;i<size;i++) printf("%d ", p[i]);
    printf("\n");
}
