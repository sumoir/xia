/*
 * connect.h
 *
 *  Created on: 2022年8月28日
 *      Author: xia
 */

#ifndef CONNECT_H_
#define CONNECT_H_

#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdint.h>


int client_connection_server(char *ip,int port);
int server_connect_from_client(char *ip,int port);
#endif /* CONNECT_H_ */
