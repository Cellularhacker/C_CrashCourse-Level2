/*
* 2016-07-14
* 파일 분리 프로젝트
* main.c
* Cellularhacker
* GNU General Public License v3.0
*/
#include <stdio.h>
#include "Sorting.h"
#include "Fileio.h"
#include "Functions.h"

int main(int argc, char* argv[]) {
    int *arr;
    int size=0;
    
    printf("\n출력할 Round 입력>> ");
    scanf("%d",&rnd);

    arr = openFile(argv[1], &size);
    //Sorting Codes;
    Sorting_main(arr, size)

    saveFile(argv[1], arr, size);

    printf("\n");
    return 0;
}

