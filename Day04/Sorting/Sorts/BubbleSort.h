/*
* 2016-07-14
* 파일 분리 프로젝트
* BubbleSort.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef Bubble_H
#define Bubble_H
void BubbleSort(int *p, int size, int round);
#endif

#ifndef printArr_Func
#define printArr_Func
void printArr(int *p, int size);
#endif

void BubbleSort(int *p, int size, int round) {
    int i, tmp, rnd_i=0;
    for(i=0;i<size-1;i++) {
        if(p[i] > p[i+1]) {  //오름차순: >, 내림차순: <
            tmp = p[i];
            p[i] = p[i+1];
            p[i+1] = tmp;
        }
        
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