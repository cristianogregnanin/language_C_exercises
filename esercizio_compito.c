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
int main()
{
    int client_socket,server_socket,pid;
    struct sockaddr_in server_addr,client_addr;
    int p1p2[2];
    char buffer[dim];
    char path[dim];
    char str[dim];
    int fromlen=sizeof(server_addr);

    server_socket=socket(AF_INET,SOCK_STREAM,0);
    if(server_socket<0)
    {
        printf("errore\n");
        exit(1);
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=port;
    server_addr.sin_addr.s_addr=INADDR_ANY; 

    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))<0)
    {
        printf("errore di binding\n");
        exit(1); 
    }
    pipe(p1p2);
    while(1)
    {
        listen(server_socket, 10);
		printf("\n\nServer in ascolto...\n");

        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &fromlen);

        pid=fork();
        if(pid==0)
        {
            close(server_socket);
            int nread=read(client_socket,buffer,sizeof(buffer));
            sprintf(path,"%s",strtok(buffer," "));
            sprintf(str,"%s",strtok(NULL," "));
            close(1);
            close(p1p2[0]);
            dup(p1p2[1]);
            close(p1p2[1]); //ovviamente 
            execl("/usr/bin/grep","grep","-0",path,str,NULL);
            return -1; 
        }
        pid=fork();
        if(pid==0)
        {
            close(0);
            close(p1p2[1]);
            dup(p1p2[0]);
            close(p1p2[0]);
            close(1);
            dup(client_socket);
            close(client_socket);
            execl("/usr/bin/wc","wc","-l",NULL);
            return -1; 
        }

        close(client_socket);
    }
    close(server_socket);
    return -1; 
}