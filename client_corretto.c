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
#define SERVER_PORT 40000

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }
    struct sockaddr_in servizio;
    int nread, socketfd;
    char buff[DIMBUFF];
    memset((char *)&servizio, 0, sizeof(servizio));
    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(atoi(argv[3]));
    servizio.sin_addr.s_addr = inet_addr(argv[2]);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) == -1)
    {
        exit(1);
    }
    printf("Stabilita la connessione con il server..\n");
    write(socketfd, argv[1], strlen(argv[1]));
    while ((nread = read(socketfd, buff, DIMBUFF)) > 0)
    {
        write(1, buff, nread);
    }
    if (nread < 0)
    {
        exit(1);
    }
    printf("dopo il while ma prima della close\n");
    close(socketfd);
    printf("dopo la close\n");
    return 0;
}

/*Ho corretto la dichiarazione di buff per avere una dimensione di DIMBUFF.
Ho aggiunto la gestione degli errori per la funzione connect, in caso di connessione fallita.
Ho modificato la condizione del ciclo while per assicurarmi che il loop termini correttamente se la lettura restituisce zero (indicando la fine del file) o un errore (valore negativo).
Ho aggiunto la gestione degli errori per la funzione read, se la lettura ha esito negativo.*/