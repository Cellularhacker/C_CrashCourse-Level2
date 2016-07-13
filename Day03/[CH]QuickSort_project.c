/*
* 2016-07-12
* 퀵정렬 - 프로젝트
* QuickSort_project.c
* Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SORTNAME "퀵정렬"

void QuickSort(int *p, int left, int right);
void printArr(int *p, int arr_size);
int *openFile(char *filename);
void saveFile(char *filename, int *p);

int rnd = 0;
int rnd_i = 1;
int size = 0;


int main(int argc, char* argv[]) {
    int *arr;
    
    printf("\n출력할 Round 입력>> ");
    scanf("%d",&rnd);

    arr = openFile(argv[1]);
    QuickSort(arr, 0, size-1);
    saveFile(argv[1], arr);

    printf("\n");
    return 0;
}

void QuickSort(int *p, int left, int right) {
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
        QuickSort(p, left, j); 
    if(i < right)
        QuickSort(p, i, right);
    if(rnd_i == rnd) printArr(p, size);
    rnd_i++;
}

void printArr(int *p, int arr_size) {
    int i;
    
    for(i=0;i<arr_size;i++) printf("%d ",p[i]);
    printf("\n");    
}

int *openFile(char *filename) {
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

    size = i;
    p = (int*) malloc( sizeof(int)*(size));
    for(i=0;i<(size);i++)
        p[i] = tmp_arr[i];
    free(tmp_arr);
    
    fclose(fp);

    return p;    
}


void saveFile(char *filename, int *p) {
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
