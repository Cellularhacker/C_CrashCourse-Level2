/*
* 2016-07-14
* 파일 분리 프로젝트
* Functions.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef Functions_H
#define Functions_H
void printArr(int *p, int size);
#endif

void printArr(int *p, int size) {
    int i;

    printf("Result=> ");
    for(i=0;i<size;i++) printf("%d ",p[i]);
    printf("\n");
}