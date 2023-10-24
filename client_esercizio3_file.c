#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define dim 1024
#define port 40000
int main()
{
    int client_socket;
    struct sockaddr_in server_addr; 
    char buffer[dim]; 
    char carratere;
    FILE *fd;
    fd=fopen("file.txt","r");
    fscanf(fd,"%s",buffer);
    fclose(fd);
    printf("inserisci il carattere che vuoi cercare\n");
    scanf("%s",&carratere);

    client_socket=socket(AF_INET,SOCK_STREAM,0);
    if(client_socket<0)
    {
        printf("errore\n");
        exit(1);
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=port;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(client_socket,(struct sockaddr*)&server_addr,sizeof(server_addr));

    write(client_socket,"%s",strlen(buffer));
    write(client_socket,"%s",sizeof(carratere));
    printf("stringa e carattere inviata\n");

    char risposta[dim];
    recv(client_socket,risposta,sizeof(risposta),0);
    printf("il carattere è stato trovato %s volte\n",risposta);
    close(client_socket);
    return 0; 
}