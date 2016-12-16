#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MESSAGE_BUFFER_SIZE 100;

server_handshake(int *from_client);
client_handshake(int *to_server);


server_handshake(int *from_client){
	mkfifo("mal", 0644);

	int pd = open("mal", RD_ONLY | 0644);
	printf("Receiving message...\n");

	int clientfifo;
	read(pd, clientfifo, sizeof(clientfifo));

	int err = remove("mal");

	char *s;
	itoa(clientinfo, s, sizeof(clientinfo));

	int cd = open(s, WR_ONLY | 0644);
	char *m = "Message Received!";
	write(cd, m, sizeof(m));

	char *incoming;
	read(pd, incoming, MESSAGE_BUFFER_SIZE);







}


