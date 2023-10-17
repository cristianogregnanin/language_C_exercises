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

#define DIMBUFF 512

int main(int argc, char *argv[])
{   
    //  0       1          2         3
    //a.out nome_file ip_server porta_server
    if(argc != 4)
    {
        printf("Numero argomenti errato.\n");
        exit(1);
    }

    char buff;
    int nread, socketfd;
    struct sockaddr_in servizio;
    
    memset((char *)&servizio,0,sizeof(servizio));  //zona di memoria di servizio svuotata
    servizio.sin_family = AF_INET; //famiglia socket
    servizio.sin_addr.s_addr = inet_addr(argv[2]); //dest address
    servizio.sin_port = htons(atoi(argv[3]));//server port

    socketfd = socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr *)&servizio,sizeof(servizio)); //connessione al server
    printf("Connessione stabilita.\n");

    write(socketfd,argv[1],strlen(argv[1])); //invio nome del file da ricercare nel server
    while(nread = read(socketfd,buff,sizeof(buff))>0)
    {
        write(1,buff,nread);//scrittura su STD_OUT dei dati ricevuti (contenuto del file richiesto)
    }
    
    close(socketfd); //chiusura della socket;
    return 0;
}