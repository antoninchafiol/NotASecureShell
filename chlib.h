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


void printActualInfo(int port);
int prepareTCPClient(const char* name, const char* port);
int prepareTCPServer(int maxClients, int port);

#define MAX_PORT_LENGTH 6
#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_RESET   "\x1b[0m"

#define HINTS_TCP_CLI(hints) \
    memset(&hints, 0, sizeof(struct addrinfo));\
    hints.ai_family = AF_INET;\
    hints.ai_flags = AI_CANONNAME;\
    hints.ai_socktype = SOCK_STREAM;

#define HINTS_TCP_SERV(hints)  \
    memset(&hints, 0, sizeof(struct sockaddr_in));\
    hints.sin_family = AF_INET;

/*
#define TCPACCEPT(namefd, sock) \
    if((namefd = accept(sock, NULL, NULL)) == -1){ 
        perror("Error accept"); \
        exit(1);\
    }
    */

#define TEST_PASSED (printf("["C_GREEN" ✔ "C_RESET"]"))
#define TEST_FAILED (printf("["C_RED" ✘ "C_RESET"]"))

