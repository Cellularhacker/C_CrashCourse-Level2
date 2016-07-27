/*
* 2016-07-14
* 파일 분리 프로젝트
* Fileio.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef Fileio_H
#define Fileio_H
int *openFile(char *filename, int *arr_size);
void saveFile(char *filename, int *p, int size);
#endif


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

    println();

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