/*
* 2016-07-12
* 선택정렬 - 프로젝트
* SelectionSort_project.c
* Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    //printf("\nSelectionSort Called! \n\tsize=%d, round:%d\n",size,round); //DEBUG CODE
    for(i=0;i<size-1;i++) {
        index = i;
        for(j=i+1;j<size;j++) {
            //printf("\tㄴNow calling if(p[j] < p[index] )...\n"); //DEBuG CODE
            //printf("\t=> i:%d, j:%d, index:%d\n",i,j,index); //DEBUG CODE
            //printf("\t=> p[i]:%d, p[j]:%d, p[index]:%d\n",p[i],p[j],p[index]); //DEBUG CODE
            if( p[j] < p[index] ) index = j;
        }
        //printf("\tㄴNow swaping p[index] <--> p[i]<\n"); //DEBUG CODE
        tmp = p[index];
        p[index] = p[i];
        p[i] = tmp;

        //printf("Calling printArr\n"); //DEUBG CODE
        //printf("[%d Round]: ",i); printArr(p, size); //DEUBG CODE
        if(i==round) { printf("[%d Round]: ",i); printArr(p, size); }
    }
    //printf("SelectionSort END\n"); //DEUBG CODE
}

void printArr(int *p, int size) {
    int i;
    
    //printf("printArr Called\n"); //DEUBG CODE
    for(i=0;i<size;i++) printf("%d ",p[i]);
    //printf("printArr END\n"); //DEBUG CODE
    printf("\n");    
}

int *openFile(char *filename, int *arr_size) {
    FILE *fp;
    int index, fSize=0, data;
    int *tmp_arr, *p;
    int i=0;
    
    //printf("openFile() Called!\n"); //DEBUG CODE
    
    fp = fopen(filename, "r"); //파일을 읽기전용으로 열기
    fseek(fp, 0L, SEEK_END); //파일 크기를 구하기 위해 맨 뒤로 이동
    fSize = ftell(fp);  //파일 크기를 기록
    fseek(fp, 0L, SEEK_SET); //다시 커서를 앞으로 이동
    
    //printf("\tfilename: %s, fSize: %d\n",filename,fSize); //DEBUG CODE
    
    tmp_arr = (int*) malloc( sizeof(int)*fSize );    

    //printf("[Before fscanf]\n"); //DEBUG CODE
    
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
    
    //printf("saveFile Called\n"); //DEBUG CODE
    for(i=sizeof(filename)-2;i>=0;i--) {
        //printf("\tㄴi:%d, filename[i]:%c\n",i,filename[i]); //DEBUG CODE
        if(filename[i] == '.') {
            str1 = (char*) malloc(i);
            for(j=0;j<i;j++) str1[j] = filename[j];

            //printf("\tㄴstrcpy(str1, filename); has been completed!\n"); //DEBUF CODE
            //printf("\tㄴi:%d, sizeof(*str1):%lu, str1:%s, filename:%s\n",i,sizeof(*str1),str1,filename); //DEBUG CODE
            strcpy(save_filename, str1);
            //printf("\tㄴstr1:%s, save_filename:%s\n",str1,save_filename);//DEBUF CODE
            strcat(save_filename, "_out.txt");
            //printf("\tㄴstr1:%s, save_filename:%s\n",str1,save_filename);//DEBUF CODE
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

    //printf("saveFile END\n"); //DEBUG CODE
}
