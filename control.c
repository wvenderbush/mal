#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h> 
#include <sys/stat.h>

#define MESSAGE_BUFFER_SIZE 100

void process(char *s){

}

int server_handshake(int from_client){

}

int main() {

	int to_client, from_client;
	char buffer[MESSAGE_BUFFER_SIZE];

	to_client = server_handshake(&from_client);

	while (1){

	read(from_client, buffer, sizeof(buffer));
	process(buffer);
	write(to_client, buffer, sizeof(buffer));

	}

	return 0;

}