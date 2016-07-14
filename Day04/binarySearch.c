/*
* 2016-07-14
* 이진탐색
* binarySearch.c
* Cellularhacker
*/

#include <stdio.h>
#include <stdlib.h>
#define println() printf("\n")
#define division_line "\n===================================\n"
#define SEARCHNAME "이진탐색"

void binarySearch(int *p, int left, int right, int key);
void printArr(int *p, int size);
int *openFile(char *filename, int *arr_size);
//void saveFile(char *filename, int *p, int size);

int main(int argc, char* argv[]) {
    int size = 0;
    int *arr;
    int key;

    printf(division_line);
    printf("<"SEARCHNAME">\n");

    printf("\n찾을 값 입력>> ");
    scanf("%d",&key);

    arr = openFile(argv[1], &size);
    binarySearch(arr, 0, size-1, key);
    //saveFile(argv[1], arr, size);

    printf(division_line);
    println();

    free(arr);
    return 0;
}


void binarySearch(int *p, int left, int right, int key) {
    int b_left = left, b_right = right;
    int flag = (left + right)/2;
    
    if(p[flag]==key) {
        printf("\t값을 찾았습니다! 찾으시는 키 값은 %d번째에 있습니다.\n",flag+1);
        return;
    } else {
        if(left==right) {
        printf("값을 찾을 수 없습니다... \n찾으시는 값이 %d(이)가 맞는지 다시한번 확인해 주세요.\n",key);
        return;
    }

        if(key > p[flag])
            binarySearch(p, flag+1, b_right, key);
        else if(key < p[flag])
            binarySearch(p, b_left, flag-1, key);
    }
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

    //printf("[%s]=> ",filename); //USELESS CODE IN THIS PROJECT
    while(fscanf(fp, "%d ", &data) != EOF) {
        tmp_arr[i] = data;
        //printf("%d ",tmp_arr[i]); //USELESS CODE IN THIS PROJECT
        i++;
    }

    println();

    *arr_size = i;
    p = (int*) malloc( sizeof(int)*(*arr_size));
    for(i=0;i<(*arr_size);i++)
        p[i] = tmp_arr[i];
    free(tmp_arr);
    
    fclose(fp);

    return p;    
}

/*
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
}*/
