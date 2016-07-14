/*
* 2016-07-14
* 파일 분리 프로젝트
* SelectionSort.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef SelectionSort_H
#define SelectionSort_H
void Selectionort(int *p, int size, int round);
#endif

#ifndef printArr_Func
#define printArr_Func
void printArr(int *p, int size);
#endif

void SelectionSort(int *p, int size, int round) {
    int i,j,tmp,index,rnd_i=0;

    for(i=0;i<size-1;i++) {
        index = i;
        for(j=i+1;j<size;j++) {
            if( p[j] < p[index] ) index = j;
        }
        tmp = p[index];
        p[index] = p[i];
        p[i] = tmp;

        rnd_i++;
        if(round==rnd_i) printArr(p, size);
    }
}

void printArr(int *p, int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    printf("\n");
}