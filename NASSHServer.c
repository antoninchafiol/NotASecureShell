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

void * executeCommand(void* args){
    int *sock = (int*)args;
    char buffer[2048];
    recv(*sock, buffer, 2048, 0);
    printf("buffer : %s\n", buffer);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    if(argc!=1){
        printf("Usage : %s \n", argv[0]);
        exit(1);
    }
    struct sockaddr_in f;
    int sock = 0, ret_bind = 0;
    memset(&f, 0, sizeof(struct sockaddr_in));

    f.sin_family = AF_INET;
    f.sin_port = htons(atoi("6666"));

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Error socket");
        exit(1);
    }
    if((ret_bind = bind(sock, (struct sockaddr*)&f, sizeof(f)))==-1){
        perror("Erreur when binding");
        exit(1);
    }

    if(listen(sock, 5) ==-1){
        perror("listen error");
        exit(1);
    }
    printf("Listening.....\n\n");
    while (1)
    {
        int cfd;
        if((cfd = accept(sock, NULL, NULL)) == -1){
            perror("error accept server\n");
            exit(1);
        }
        printf("accepted\n");
        pthread_t th;
        pthread_create(&th, NULL, executeCommand, (int *)&cfd);
    }
    

    return 0;
}
