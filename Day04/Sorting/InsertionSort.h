/*
* 2016-07-14
* 파일 분리 프로젝트
* InsertionSort.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef InsertionSort_H
#define InsertionSort_H
void InsertionSort(int *p, int size, int round);
#endif

void InsertionSort(int *p, int size, int round) {
    int tmp, i, j, rnd_i=0;
    
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

        rnd_i++;
        if(round==rnd_i) printArr(p, size);
    }
}