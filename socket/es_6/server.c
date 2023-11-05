#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define DIM 200

void EliminaCarattere(char stringa[], char c)
{
    for (int i = 0; i < DIM; i++)
    {
        if (stringa[i] == c)
        {
            for (int j = i; j < DIM - i; j++)
            {
                stringa[j] = stringa[j + 1];
            }
            i--;
        }
    }
}
void controllaParametri(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Non hai inserito i parametri necessari \n");
        printf("Uso: $./server <porta>\n");
        exit(0);
    }
}

int main(int argc, char *argv[])
{

    controllaParametri(argc, argv);

    struct sockaddr_in servizio, rem_indirizzo;
    int soa, pid, socketfd, on = 1, fromlen = sizeof(servizio);
    char car, stringa[DIM], stringaout[DIM];

    memset((char *)&servizio, 0, sizeof(servizio));

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(atoi(argv[1]));

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    listen(socketfd, 10);
    for (;;)
    {
        printf("\n Server in ascolto... \n");

        soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &fromlen);

        int nread = read(soa, stringa, sizeof(stringa));
        printf("\tstringa: %s\n\n", stringa);
        write(soa, &nread, sizeof(nread));

        read(soa, &car, sizeof(car));
        printf("\tcarattere: %c\n\n", car);
        EliminaCarattere(stringa, car);
        int lunghezza = strlen(stringa);
        printf("\tLa stringa senza il carattere è %s, lunghezza: %d\n", stringa, lunghezza);

        write(soa, stringa, strlen(stringa) + 1); // https://stackoverflow.com/a/18187293

        close(soa);
    }
    close(socketfd);
    return 0;
}
