/*
* 2016-07-12
* 삽입정렬 - 프로젝트
* InputingSort_project.c
* Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "삽입정렬"

void SelectionSort(int *p, int size, int round);
void printArr(int *p, int size);
int *openFile(char *filename, int *arr_size);
void saveFile(char *filename, int *p, int size);

int main(int argc, char* argv[]) {
    int size = 0;
    int *arr;
    int round = 0;
    
    printf("\n출력할 Round 입력>> ");
    scanf("%d",&round);

    arr = openFile(argv[1], &size);
    SelectionSort(arr, size, round);
    saveFile(argv[1], arr, size);

    printf("\n");
    return 0;
}

void SelectionSort(int *p, int size, int round) {
    int i,j,tmp,index;

    for(i=0;i<size-1;i++) {
        index = i;

        for(j=i+1;j<size;j++) {
            if( p[j] < p[index] ) index = j;
        }
        tmp = p[index];
        p[index] = p[i];
        p[i] = tmp;

        if(i==round) { printf("[%d Round]: ",i); printArr(p, size); }
    }
}

void printArr(int *p, int size) {
    int i;
    
    for(i=0;i<size;i++) printf("%d ",p[i]);

    printf("\n");    
}

int *openFile(char *filename, int *arr_size) {
    FILE *fp;
    int index, fSize=0, data;
    int *tmp_arr, *p;
    int i=0;
    
    fp = fopen(filename, "r"); //파일을 읽기전용으로 열기
    fseek(fp, 0L, SEEK_END); //파일 크기를 구하기 위해 맨 뒤로 이동
    fSize = ftell(fp);  //파일 크기를 기록
    fseek(fp, 0L, SEEK_SET); //다시 커서를 앞으로 이동
    
    tmp_arr = (int*) malloc( sizeof(int)*fSize );    
    
    printf("[%s]=> ",filename);
    while(fscanf(fp, "%d ", &data) != EOF) {
        tmp_arr[i] = data;
        printf("%d ",tmp_arr[i]);
        i++;
    }

    printf("\n");

    *arr_size = i;
    p = (int*) malloc( sizeof(int)*(*arr_size));
    for(i=0;i<(*arr_size);i++)
        p[i] = tmp_arr[i];
    free(tmp_arr);
    
    fclose(fp);

    return p;    
}


void saveFile(char *filename, int *p, int size) {
    FILE *fp;
    int i, j;
    char save_filename[strlen(filename)+4];
    char *str1;
    
    for(i=sizeof(filename)-2;i>=0;i--) {
        if(filename[i] == '.') {
            str1 = (char*) malloc(i);
            for(j=0;j<i;j++) str1[j] = filename[j];

            strcpy(save_filename, str1);
            strcat(save_filename, "_out.txt");
            break;
        }
    }
    fp = fopen(save_filename, "w+");
    for(i=0;i<size;i++) fprintf(fp, "%d ",p[i]);
    fprintf(fp, "\n",p[i+1]);
    
    fclose(fp);

    printf("Result has been successfully saved in [%s] !\n",save_filename);
    free(p);
    free(str1);
}
