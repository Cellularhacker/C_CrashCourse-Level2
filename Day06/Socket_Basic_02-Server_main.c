/*
* 2016-07-21
* Socket_Basic_02
* Socket_Basic_02-Server_main.c
* Cellularhacker
* General GNU/Public License v3.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#define BUF_SIZE 1024
void ErrorHandling(char *message);

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	char message[BUF_SIZE];
	int strLen, i=0, clnAdrSize;
	int for_i=0, tmp=0, sum=0;
	SOCKADDR_IN servAdr, clntAdr;
	
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	if(WSAStartup(MAKEWORD(2,2), &wsaData) !=0 ) ErrorHandling("WSAStartup() Error!");
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if(hServSock == INVALID_SOCKET) ErrorHandling("socket() error");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port=htons(atoi(argv[1]));
	
	if(bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");
	
	if(listen(hServSock, 5) == SOCKET_ERROR) ErrorHandling("listen() error");
	clnAdrSize = sizeof(clntAdr);
	
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clnAdrSize);
	if(hClntSock == -1) ErrorHandling("accpet() error");
		else {
		printf("Connected client %d \n", i+1);
		
		while((strLen = recv(hClntSock, message, BUF_SIZE, 0)) != 0) {}
			if(for_i >= 5) {
				itoa(sum,message,10);
				
				send(hClntSock, message, strLen, 0);
				for_i = 0;
				sum = 0;
			} 
			tmp = atoi(message);
			sum += tmp;
			for_i++;
			
			closesocket(hClntSock);
		}
	
	
	closesocket(hServSock);
	WSACleanup();
	
	return 0;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
