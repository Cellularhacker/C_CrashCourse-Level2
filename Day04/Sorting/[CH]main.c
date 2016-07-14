/*
* 2016-07-14
* 파일 분리 프로젝트
* main.c
* Cellularhacker
* GNU General Public License v3.0
*/
#include <stdio.h>
#include "Sorting.h"

int main(int argc, char* argv[]) {
    int *arr;
    
    printf("\n출력할 Round 입력>> ");
    scanf("%d",&rnd);

    arr = openFile(argv[1]);
    //Sorting Codes;
    saveFile(argv[1], arr);

    printf("\n");
    return 0;
}
