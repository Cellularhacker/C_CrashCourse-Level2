/*
* 2016-07-28
* Socket_BaseBall_Game_Project
* Socket_BaseBall_Server.c
* Cellularhacker
* General GNU/Public License v3.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winSock2.h>
#include <time.h>


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

void Error(char *message);
void initBBR(BBR *baseball_result_struct);
void resetBBR(BBR *baseball_result_struct);
void initBB(BB *baseball_struct);
void resetBB(BB *baseball_struct);
BBR CheckBBR(BB *bb_srv, BB *bb_cli);


int main(int argc, char *argv[])
{
	WSADATA wsadata;
	SOCKET hServSock, hClntSock;
	BB bb_srv, bb_cli;
	BBR bbr_cli;
	int for_i;
	int clntAdrsize, strLen, i;
	char keyboard_e;
	SOCKADDR_IN servAdr, clntAdr;
	
	//Initialize strcuts.
	initBB(&bb_srv);
	initBB(&bb_cli);
	initBBR(&bbr_cli);

	if (argc != 2)
	{
		printf("USAGE : %s <port> \n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		Error("WSAStartup() error!");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		Error("socket() errer!");

	memset(&servAdr, 0, sizeof(servAdr));

	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR *)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		Error("bind() error!");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		Error("listen() error!");

	clntAdrsize = sizeof(clntAdr);

	hClntSock = accept(hServSock, (SOCKADDR *)&clntAdr, &clntAdrsize);
	if (hClntSock == -1)
		Error("accpet() error!");
	else
		printf("connected client %d \n", ++i);

	while (1)
	{
		printf("Press \'Ctrl + C\' to quit...\n");
	
		while(bbr_cli.strike < 3) {
			recv(hClntSock, (char *)&bb_cli, sizeof(bb_cli), 0);
			
			CheckBBR(&bb_srv, &bb_cli);
			
			send(hClntSock, (char *)&bbr_cli, sizeof(BBR), 0);
		}
		
		
		
		//Reset This Round's Numbers.
		resetBB(&bb_srv);
		resetBB(&bb_cli);
		resetBBR(&bbr_cli);
	}

	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();

	return 0;
}


void resetBBR(BBR *baseball_result_struct) {
	baseball_result_struct->ball = 0;
	baseball_result_struct->strike = 0;
	baseball_result_struct->key++;
}

void initBBR(BBR *baseball_result_struct) {
	baseball_result_struct->ball = 0;
	baseball_result_struct->strike = 0;
	baseball_result_struct->key = 0;
}


void initBB(BB *baseball_struct) {
	srand((unsigned)time(NULL));
	
	baseball_struct->arr[0] = (rand() %10);
	while(baseball_struct->arr[1] != baseball_struct->arr[0]) baseball_struct->arr[1] = (rand() %10);
	while( (baseball_struct->arr[2] != baseball_struct->arr[0]) && (baseball_struct->arr[2] != baseball_struct->arr[1])) baseball_struct->arr[2] = (rand() %10);
	baseball_struct->key = 0;
}

void resetBB(BB *baseball_struct) {
	srand((unsigned)time(NULL));
	
	baseball_struct->arr[0] = (rand() %10);
	while(baseball_struct->arr[1] != baseball_struct->arr[0]) baseball_struct->arr[1] = (rand() %10);
	while( (baseball_struct->arr[2] != baseball_struct->arr[0]) && (baseball_struct->arr[2] != baseball_struct->arr[1])) baseball_struct->arr[2] = (rand() %10);
	baseball_struct->key++;
}

BBR CheckBBR(BB *bb_srv, BB *bb_cli) {
	BBR bbr_calc;
	initBBR(&bbr_calc);
	int for_srv, for_cli;
	
	if(bb_srv->key == bb_cli->key) {
		bbr_calc.key = bb_cli->key;
		
		for(for_srv=0;for_srv<3;for_srv++) {
			for(for_cli=0;for_cli<3;for_cli++) {
				if(bb_srv->arr[for_srv] == bb_cli->arr[for_cli]) {
					if(for_srv == for_cli) bbr_calc.strike++;//Judges Strike it is.
				} else bbr_calc.ball++;
			}
		}
	} else {
		Error("Error occured at CheckBBR Func: key didn't match.'");
		exit(-1);
	}
	
	return bbr_calc;
}


void Error(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
