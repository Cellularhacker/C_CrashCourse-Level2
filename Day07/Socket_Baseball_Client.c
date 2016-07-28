/*
* 2016-07-28
* Socket_BaseBall_Game_Project
* Socket_BaseBall_Client.c
* Cellularhacker
* General GNU/Public License v3.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winSock2.h>


int func(int a, int b, char c);

typedef struct baseball{
	int arr[3];
	unsigned int key;
}BB;

typedef struct baseball_result{
	int ball;
	int strike;	
	unsigned int key;
}BBR;

void ErrorHandling(char *message);
void initBBR(BBR *baseball_result_struct);
void resetBBR(BBR *baseball_result_struct);
void initBB(BB *baseball_struct);
void resetBB(BB *baseball_struct);
void printBBR(BBR *bbr_cli);


int main(int argc, char *argv[])
{
	WSADATA wsaData;
	SOCKET hSocket;
	BB bb_srv, bb_cli;
	BBR bbr_cli;
	int for_i;
	int clntAdrsize, strLen, i;
	char keyboard_e;
	SOCKADDR_IN servAdr;
	
	//Initialize structs
	initBB(bb_srv);
	initBB(bb_cli);
	initBBR(bbr_cli);
	
	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0) ErrorHandling("WSAStartup() error!");
	
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(hSocket == INVALID_SOCKET) ErrorHandling("socket() error");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
	servAdr.sin_port = htons(atoi(argv[2]));
	
	if(connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");
	else
		puts("Connected...........");

	while (1)
	{
		//printf("Press \'Ctrl + C\' to quit...\n");
	
		while(1) {
			printf("순서대로 숫자 3개를 입력하세요!\n\t>>> ");
			for(for_i=0;for_i<3;for_i++) scanf("%d",&bb_cli.arr[for_i]);
			send(hSocket, (const char *)&bb_cli, sizeof(BBR), 0);
			
			recv(hSocket, (char *)&bbr_cli, sizeof(bb_cli), 0);
			printBBR(bbr_cli);
		}
		
		
		
		//Reset This Round's Numbers.
		resetBB(bb_srv);
		resetBB(bb_cli);
		resetBBR(bbr_cli);
	}

	closesocket(hSocket);
	WSACleanup();

	return 0;
}


void resetBBR(BBR *baseball_result_struct) {
	baseball_result_struct.ball = 0;
	baseball_result_struct.strike = 0;
	baseball_result_struct.key++;
}

void initBBR(BBR *baseball_result_struct) {
	baseball_result_struct.ball = 0;
	baseball_result_struct.strike = 0;
	baseball_result_struct.key = 0;
}


void initBB(BB *baseball_struct) {
	srand((unsigned)time(NULL));
	
	baseball_struct.arr[0] = (rand() %10);
	while(baseball_struct.arr[1] != baseball_struct.arr[0]) baseball_struct.arr[1] = (rand() %10);
	while( (baseball_struct.arr[2] != baseball_struct.arr[0]) && (baseball_struct.arr[2] != baseball_struct.arr[1])) baseball_struct.arr[2] = (rand() %10);
	baseball_struct.key = 0;
}

void resetBB(BB *baseball_struct) {
	srand((unsigned)time(NULL));
	
	baseball_struct.arr[0] = (rand() %10);
	while(baseball_struct.arr[1] != baseball_struct.arr[0]) baseball_struct.arr[1] = (rand() %10);
	while( (baseball_struct.arr[2] != baseball_struct.arr[0]) && (baseball_struct.arr[2] != baseball_struct.arr[1])) baseball_struct.arr[2] = (rand() %10);
	baseball_struct.key++;
}

void printBBR(BBR *bbr_cli) {
	//printf("[Game set No.%d]\n");
	printf("\nStrike: %d, Ball: %d !\n",bbr_cli.strike, bbr_cli.ball);
}


void ErrorHandling(char *message)
{
	fputs(message, stderr);
	fputc("\n", stderr);
	exit(1);
}

