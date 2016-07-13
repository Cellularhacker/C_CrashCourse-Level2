/*
* 2016-07-12
* 셸정렬
* ShellSort.c
* Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "셸정렬"

void InputingSort(int *p, const int size);
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

    InputingSort(arr, size);
    printArr(arr, size);
    
    printf(division_line);
    println();
    
    return 0;
}

void InputingSort(int *p, const int size) {
    int tmp, i, j;
    
    for(i=1;i<size;i++) {
        tmp=p[i];

        for(j=i; j>0; j--) {
            if(p[j - 1] > tmp) {
                p[j] = p[j - 1];
                if(j == 1) {
                    p[j - 1] = tmp;
                    break;
                }
            }
            else {
                p[j] = tmp;
                break;
            }
        }
    }
}

void printArr(int *p, const int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    println();
}
