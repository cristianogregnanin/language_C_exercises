#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#define dim 1024
#define port 40000
int main(int argc, char*argv[])
{
    if(argc!=3)
    {
        printf("errore\n");
        return 0; 
    }
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[dim];

    client_socket=socket(AF_INET,SOCK_STREAM,0);
    if(client_socket<0)
    {
        printf("errore\n");
        exit(1);
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=port;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(connect(client_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
    {
        printf("errore di connessione\n");
        exit(1);
    }

    sprintf(buffer,"%s %s",argv[1],argv[2]); 
    write(client_socket,buffer,strlen(buffer));
    printf("stringa inviata e percorso inviato\n");

    read(client_socket,buffer,sizeof(buffer));
    printf("%s\n",buffer); 
    close(client_socket);
    return 0; 
}