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
#define SOCKET_ERROR -1
#define DIMBUFF 512

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio, rem_indirizzo;
    int pid, soa, socketfd, on = 1, fromlen,nread;
    socklen_t client_len;
    char nome_file[DIMBUFF];
    memset(&servizio, 0, sizeof(servizio));

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVER_PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    //Verificato se le chiamate di sistema (socket(), setsockopt(), bind(), listen(), accept(), read()) hanno restituito errori e gestito gli errori stampando un messaggio di errore e uscendo in caso di errore.
    if (socketfd == SOCKET_ERROR)
    {
        perror("socket");
        exit(1);
    }
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == SOCKET_ERROR)
    {
        perror("setsockopt");
        exit(1);
    }
    if (bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) == SOCKET_ERROR)
    {
        perror("bind");
        exit(1);
    }
    if (listen(socketfd, 10) == SOCKET_ERROR)
    {
        perror("listen");
        exit(1);
    }
    client_len = sizeof(rem_indirizzo);
    for (;;)
    {
        printf("\n\nServer in ascolto...\n");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &client_len);
        if (soa == SOCKET_ERROR)
        {
            perror("accept");
            exit(1);
        }
        pid = fork();
        if (pid == 0)
        {
            close(socketfd);
            nread = read(soa, nome_file, DIMBUFF);
            if (nread == -1)
            {
                exit(1);
            }
            nome_file[nread] = '\0';
            printf("invio nome file: %s\n", nome_file);
            fflush(stdout);
            close(1);
            dup(soa);
            close(soa);
            execl("/usr/bin/cat", "cat", nome_file, (char *)0);
            return -1; //Aggiunto il controllo dell'errore per execl().
            exit(1);
        }
        close(soa);
    }
    close(socketfd);
    return 0;
}
