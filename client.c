#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

int main() {
  printf("Client initiated...\n");

  int to_server, from_server;

  from_server = client_handshake( &to_server );

  while (1){
  char buffer[MESSAGE_BUFFER_SIZE];
  printf("Enter Message: ");
  fgets( buffer, sizeof(buffer), stdin );
  char *p = strchr(buffer, '\n');
  *p = 0;

  
	  write( to_server, buffer, sizeof(buffer) );
	  read( from_server, buffer, sizeof(buffer) );
	  printf( "Received: %s\n\n", buffer );
  }
  
  return 0;
}
