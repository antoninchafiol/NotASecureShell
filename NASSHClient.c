#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "chlib.h"

#define PORT "6666"

int main(int argc, char const *argv[])
{
    if(argc!=3){
        printf("Usage: %s <address> <command> \n", argv[0]);
        exit(1);
    }

    

    int sock = 0; 
    sock = prepareTCPClient(argv[1], PORT);
    printf("%s\n", argv[2]);
    char cmdsend[1024];
    char messagerecv[1024];
    printf("=========================\n");
    send(sock, argv[2], 1024, 0);
    printf("Command sent : %s\n", argv[2]);
    printf("=========================\n");
    recv(sock, messagerecv, 1024, 0);
    printf("Response : vvv\n\n");
    printf("\n%s\n", messagerecv);
    


    return 0;
}
