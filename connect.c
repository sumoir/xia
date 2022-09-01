/*
 * connect.c
 *
 *  Created on: 2022年8月29日
 *      Author: xia
 */


#include <stdio.h>
#include "connect.h"
int client_connection_server(char *ip,int port) {
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	serv_addr.sin_port = htons(port);

	while (connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))) {
		sleep(1);
		printf("wait serve\r\n");
	}

	printf("OK\n");

	return sock;

}

int server_connect_from_client(char *ip,int port) {

	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in serv_addr;

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	serv_addr.sin_port = htons(port);
	bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

	listen(serv_sock, 20);
	printf("Start listening\n");

	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr,
			&clnt_addr_size);
	//连接
	printf("OK\n");
	return clnt_sock;

}

