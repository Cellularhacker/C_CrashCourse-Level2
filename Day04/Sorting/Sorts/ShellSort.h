/*
* 2016-07-14
* 파일 분리 프로젝트
* ShellSort.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef ShellSort_H
    #define ShellSort_H
    void ShellSort(int *p, int size, int round);
#endif

#ifndef printArr_Func
    #define printArr_Func
    void printArr(int *p, int size);
#endif

void ShellSort(int *p, int size, int round) {
    int gap, i, j, x, tmp, rnd_i=0;
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