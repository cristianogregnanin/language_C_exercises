#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

#define SERVER_PORT 40000

int main(int argc, char *argv[])
{
    int on = 1; // opzione della socket
    struct sockaddr_in servizio, remoto;

    memset((char *)&servizio, 0, sizeof(servizio));
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY); // localhost - 127.0.0.1
    servizio.sin_port = htons(SERVER_PORT);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)); // set socket option
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));  // viene legato l'indirizzo alla socket

    listen(socketfd, 10); // il server è in ascolto

    for (;;)
    {
        printf("Server in ascolto...\n\n");
        fflush(stdout);

        int add_len = sizeof(servizio);

        int soa = accept(socketfd, (struct sockaddr *)&remoto, &add_len); // collegamento all'host

        if (fork() == 0) // processo figlio che aiuterà il server a inviare il contenuto del file al client
        {
            char nome_file[20];
            close(socketfd);                         // chiusura del file descriptor duplicato
            read(soa, nome_file, sizeof(nome_file)); // si legge il contenuto della socket
            printf("Invio del file %s\n\n", nome_file);

            fflush(stdout);

            dup2(soa, 1);
            execl("/usr/bin/cat", "cat", nome_file, NULL);
            return -1;
        }
        close(soa);
    }

    close(socketfd);
    return 0;
}