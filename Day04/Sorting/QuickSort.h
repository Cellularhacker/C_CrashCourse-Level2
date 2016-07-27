/*
* 2016-07-14
* 파일 분리 프로젝트
* QuickSort.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef QuickSort_H
#define QuickSort_H
void QuickSort(int *p, int size, int round);
void QuickSorting(int *p, int left, int right, int round);
int quick_round = 0;
int quick_size = 0;
#endif

#ifndef printArr_Func
#define printArr_Func
void printArr(int *p, int size);
#endif

void QuickSort(int *p, int size, int round) {
    quick_size = size;
    QuickSorting(p, 0, size-1, round);
}

void QuickSorting(int *p, int left, int right, int round) {
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
        QuickSorting(p, left, j, round);
    if(i < right)
        QuickSorting(p, i, right, round);
    
    quick_round++;
    if(quick_round==round) printArr(p, quick_size);
}

void printArr(int *p, int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    printf("\n");
}