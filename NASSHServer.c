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

#define PORT 6666

void * executeCommand(void* args){
    int *sock = (int*)args;
    char buffer[2048];
    recv(*sock, buffer, 2048, 0);
    printf("buffer : %s\n", buffer);
    dup2(*sock, 1);
    dup2(*sock, 2);
    system(buffer);
    
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    if(argc!=1){
        printf("Usage : %s \n", argv[0]);
        exit(1);
    }

    int sock = 0;
    sock = prepareTCPServer(5, PORT);
    printActualInfo(PORT); 
    
    while (1)
    {
        sleep(2);
        int cfd=0;
        if((cfd = accept(sock, NULL, NULL)) == -1){ 
            perror("Error accept"); 
            exit(1);
        }
        pthread_t th;
        pthread_create(&th, NULL, executeCommand, (int *)&cfd);
    }
    

    return 0;
}
