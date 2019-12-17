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



int main(int argc, char const *argv[])
{
    char* NASSHP = "6666";
    if(argc!=3){
        printf("Usage: %s <option> <address>\n", argv[0]);
        exit(1);
    }

    if(argc==2){
        exit(1);
        // main server
    }

    int sock = 0; 
    struct addrinfo f;
    struct addrinfo *host;
    memset(&f, 0, sizeof(struct addrinfo));
    f.ai_family = AF_INET;
    f.ai_flags=AI_CANONNAME;
    f.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(argv[2], NASSHP, &f, &host)!=0){
        perror("getaddrinfo error");
        exit(1);
    }

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Socket Client");
        exit(1);
    }

    if(connect(sock, host->ai_addr, host->ai_addrlen)==-1){
        perror("Connect error");
        exit(1);
    }
    printf("yes\n");
    send(sock, "ls", 3, 0);


    return 0;
}
