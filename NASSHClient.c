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
#include "chlib/chlib.h"s

int main(int argc, char const *argv[])
{
    if(argc!=3){
        printf("Usage: %s <option> <address>\n", argv[0]);
        exit(1);
    }

    if(argc==2){
        exit(1);
        // main server
    }

    int sock = 0; 
    //HINTS_TCP_CLI(hints)
    prepareTCPClient(argv[2], 6666);

    send(sock, "ls", 3, 0);


    return 0;
}
