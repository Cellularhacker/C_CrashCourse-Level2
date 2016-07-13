/*
* 2016-07-07
* 셸정렬
* ShellSort.c
* Cellularhacker
*/
#include <stdio.h>
#define SIZE 10
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "셸정렬"

void ShellSort(int *p, const int size);
void printArr(int *p, const int size);

int main(void) {
    int i;
    int arr[SIZE] = {0};
    int arr_size = sizeof(arr)/sizeof(*arr);

    printf(division_line);
    printf("<"SORTNAME">\n");
    printf("\n[%d개 입력]>> ", SIZE);
    
    for(i=0;i<SIZE;i++)
        scanf("%d",&arr[i]);
    
    ShellSort(arr, arr_size);
    printArr(arr, arr_size);
    
    printf(division_line);
    println();
}

void ShellSort(int *p, const int size) {
    int gap, i, j, x, tmp;
    for(gap = 1; gap < (size/3); gap = (3*gap+1));
    
    while(gap>0) {
        for(x=0; x<gap; x++) {
            for(i=x+gap; i<size; i+=gap) {
                tmp = p[i];
                
                for(j=i; j>0; j-=gap) {
                    if(p[j - gap] > tmp) {
                        p[j] = p[j - gap];
                        if(j == gap) {
                            p[j - gap] = tmp;
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
        gap /= 3;
    }
}

void printArr(int *p, const int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    println();
}
