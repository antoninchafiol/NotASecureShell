#include "chlib.h"


void printActualInfo(int port){
    char name[2048];
    int res_getaddrinfo = 0;
    char c_port[MAX_PORT_LENGTH];
    sprintf(c_port, "%d", port);
    struct addrinfo filtre;
    filtre.ai_family = AF_INET;
    filtre.ai_flags = AI_CANONNAME | AI_PASSIVE;
    struct addrinfo* res;
    gethostname(name, 2048);
    if((res_getaddrinfo = getaddrinfo(name, c_port, &filtre, &res)) == -1){
        TEST_FAILED;
        perror("chlib: get the info failed");
    }
    printf("\n=============================\n");
    printf(" Server : ON \n");
    printf(" Port : %d \n", port);
    printf("===============================\n");

}

int prepareTCPClient(const char* name, const char* port){
    int sock = -1;
    struct addrinfo* host;
    struct addrinfo hints;
    HINTS_TCP_CLI(hints);
    
    if(getaddrinfo(name, port, &hints, &host) == -1){
        TEST_FAILED;
        perror("chlib: getaddrinfo TCP client");
        exit(-1);
    }
    
    TEST_PASSED;
    printf(" chlib: getaddrinfo TCP Client\n");


    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        TEST_FAILED;
        perror("chlib: socket TCP client");
        exit(-1);
    }
    TEST_PASSED;
    printf(" chlib: socket TCP Client\n");
    

    if(connect(sock, host->ai_addr, host->ai_addrlen)==-1){
        TEST_FAILED;
        perror("chlib: connect TCP client");
        exit(-1);
    } 
    TEST_PASSED;
    printf(" chlib: connect TCP Client\n");

 
    return sock;
}

int prepareTCPServer(int maxClients, int port){
    int sock = -1;
    int rbind = 0;
    struct sockaddr_in hints; 
    HINTS_TCP_SERV(hints);
    hints.sin_port = htons(port);

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        TEST_FAILED;
        perror("chlib: socket TCP server");
        exit(-1);
    }
    TEST_PASSED;
    printf(" chlib: socket TCP Server\n");

    if((rbind = bind(sock, (struct sockaddr*)&hints, sizeof(hints)))==-1){
        TEST_FAILED;
        perror("chlib: bind TCP Server");
        exit(-1);
    }
    TEST_PASSED;
    printf(" chlib: bind TCP Server\n");

    if(listen(sock, maxClients) == -1){
        TEST_FAILED;
        perror("chlib: listen TCP Server");
        exit(-1);
    }
    TEST_PASSED;
    printf(" chlib: listen TCP Server\n");

    return sock;
}
/*
int prepareUDPClient(){

}

int prepareUDPServer(){

}
*/