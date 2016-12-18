#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

void process( char * s );

int main() {
  printf("Server initiated...\n");

  int to_client, from_client;
  char buffer[MESSAGE_BUFFER_SIZE];
  
  to_client = server_handshake( &from_client );

  while (1){
	  read( from_client, buffer, sizeof(buffer) );
	  process( buffer );
	  write( to_client, buffer, sizeof(buffer));
  }
  return 0;
}


void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
