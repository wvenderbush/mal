#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

int server_handshake(int *from_client){
	mkfifo("mal", 0644);

	*from_client = open("mal", O_RDONLY);

	char message[MESSAGE_BUFFER_SIZE];
	read(*from_client, message, MESSAGE_BUFFER_SIZE);

	printf("Receiving message: %s\n", message);

	int err = remove("mal");

	int to_client = open(message, O_WRONLY);
	printf("Found private pipe: %s\n", message);

	char *confMessage = "mal";

	printf("Confirmation sent...\nConnection verified!\n");
	write(to_client, confMessage, MESSAGE_BUFFER_SIZE);

	printf("Waiting for final check message...\n");
	
	read(*from_client, message, MESSAGE_BUFFER_SIZE);
	printf("Receiving final check message: %s\n", message);

	return to_client;

}

int client_handshake(int *to_server){
	int id = getpid();
	char sid[100];
	sprintf(sid, "%d", id);

	mkfifo(sid, 0644);

	*to_server = open("mal", O_WRONLY);
	printf("Sending message...\n");

	write(*to_server, sid, sizeof(sid));

	printf("Sent pipe name: %s\n", sid);

	int from_server = open(sid, O_RDONLY);

	printf("Private connection established!\n");

	char message[MESSAGE_BUFFER_SIZE];
	read(from_server, message, MESSAGE_BUFFER_SIZE);

	printf("Confirmation message received: %s\n", message);

	write(*to_server, "mal", MESSAGE_BUFFER_SIZE);

	printf("Final check sent!\n\n");

	int err = remove(sid);

	//SHOULD SEND A MESSAGE BACK TO CONFIRM CONNECTION HAS BEEN MADE!!! (server must be looking for and reading that message)

	return from_server;

}

