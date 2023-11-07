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


void controllaParametri(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Non hai inserito i parametri necessari \n");
        printf("Uso: $./client <server-ip> <porta> <carattere>\n");
        exit(0);
    }
}

int main(int argc, char *argv[])
{

    controllaParametri(argc, argv);

    struct sockaddr_in servizio;
    int socketfd;
    memset((char *)&servizio, 0, sizeof(servizio));

    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(atoi(argv[2]));
    servizio.sin_addr.s_addr = inet_addr(argv[1]);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("Stabilita la connessione con il server..\n");

    write(socketfd, argv[3], strlen(argv[3]));

    close(0);
    dup(socketfd);
    close(socketfd);
    execl("/usr/bin/tee", "tee", "ricevuto.txt", (char *)0);
    return -1;
}