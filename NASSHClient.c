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


#define NASSHPORT 6666

int main(int argc, char const *argv[])
{
    if(argc!=4){
        printf("Usage: %s <option> <address>", argv[0]);
        exit(1);
    }

    if(argc==2){
        // main server
    }

    int sock, rb; 
    struct sockaddr_in f, host;

    f.sin_family = AF_INET;
    f.sin_port = NASSHPORT;
    getaddrinfo(argv[2], NASSHPORT, &f, &host);

    if(sock = socket(AF_INET, SOCK_STREAM, 0) == -1){
        perror("Socket Client");
        exit(1);
    }

    connect(sock, host->ai_addr, host->ai_addrlen);
    send(sock, "ls", 3, 0);


    return 0;
}
