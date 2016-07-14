/*
* 2016-07-14
* 파일 분리 프로젝트
* Sorting.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef Sorting_H
    #define Sorting_H
    #include "Sorts/SelectionSort.h"
    #include "Sorts/ShellSort.h"
    #include "Sorts/MergeSort.h"
    #include "Sorts/BubbleSort.h"
    #include "Sorts/QuickSort.h"
    #include "Sorts/InsertionSort.h"
    void Sorting_main(int *p, int size);
#endif

#ifndef printArr_Func
    #define printArr_Func
    void printArr(int *p, size);
#endif

void Sorting_main(int *p, int size) {
    int sorting, round=0;
    
    printf("(1)선택정렬, (2)셸정렬, (3)합병정렬, (4)버블정렬, (5)퀵정렬, (6)삽입정렬\n");
    printf("정렬 방법>> ");
    
    scanf("%d"&sorting);

    printf("\n출력할 Round>> ");
    scanf("%d",&round);
    printf("\n");

    switch(sorting) {
        case 1: SelectionSort(p, size, round); break;
        case 2: ShellSort(p, size, round); break;
        case 3: MergeSort(p, 0, size-1, round); break;
        case 4: BubbleSort(p, size, round); break;
        case 5: QuickSort(p, 0, size-1, round); break;
        case 6: InsertionSort(p, size, round); break;
        default: printf("\n잘못 입력 하셨습니다... 다시 입력해 주세요. \n\n"); Sorting_main(int p, size); break;
    }
}

void printArr(int *p, int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    printf("\n");
}