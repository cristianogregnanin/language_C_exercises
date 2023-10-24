#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define dim 1024
#define port 40000
int main(int argc,char*argv[])
{
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[dim];

    client_socket=socket(AF_INET,SOCK_STREAM,0);
    if(client_socket<0)
    {
        printf("errore nella creazione della socket\n");
        exit(1);
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=port;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(connect(client_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
    {
        printf("errore di connesione\n");
        exit(1);
    }
    write(client_socket,argv[1],strlen(argv[1]));

    close(0);
    dup(client_socket);
    close(client_socket);
    execl("/usr/bin/tee", "tee", "ricevuto.txt", (char *)0);
    return -1;

    return 0;
}