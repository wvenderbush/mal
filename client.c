#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h> 
#include <sys/stat.h>

int client_handshake(int to_server){

}

int main(){

	int to_server, from_server;

	from_server = client_handshake(&to_server);

	char bufer[MESSAGE_BUFFER_SIZE];


	while (1){
		printf("enter message: ");
		fgets(buffer, sizeof(buffer), stdin);
		char *p = strchr(buffer, '\n');
		*p = 0;

		write(to_server, buffer, sizeof(buffer));
		read(from_server, buffer, sizeof(buffer));

		printf("received: %s\n", buffer);
	}

return 0;


}