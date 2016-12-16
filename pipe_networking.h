#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MESSAGE_BUFFER_SIZE 100

server_handshake(int *from_client);
client_handshake(int *to_server);


int server_handshake(int *from_client){
	mkfifo("mal", 0644);

	int pd = open("mal", O_RDONLY | 0644);
	printf("Receiving message...\n");

	int clientfifo;
	read(pd, clientfifo, sizeof(clientfifo));

	int err = remove("mal");

	char *s = sprintf("%d", clientfifo);

	int cd = open(s, O_WRONLY | 0644);
	char *m = "Message Received!\n";
	write(cd, m, sizeof(m));

	char *incoming;
	read(pd, incoming, MESSAGE_BUFFER_SIZE);

	*from_client = cd;
	return pd;

}

int client_handshake(int *from_client){
	int id = getpid();
	char *sid = sprintf("%d", id);

	mkfifo(sid, 0644);

	int pd = open("mal", O_WRONLY | 0644);
	printf("Sending message...\n");

	write(pd, id, sizeof(id));

	int cd = open(sid, O_RDONLY | 0644);
	char *m = "Message Received!\n";
	printf("%s", m);

	int err = remove(sid);

	write(pd, m, sizeof(m));

	*from_client = cd;
	return pd;

}






