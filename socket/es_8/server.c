#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define DIM 20

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
    if (argc != 3)
    {
        printf("Non hai inserito i parametri necessari \n");
        printf("Uso: $./server <server-ip> -p <porta>\n");
        exit(0);
    }

    if (strcmp(argv[1], "-p") != 0)
    {
        printf("Hai inserito i parametri in maniera errata \n");
        exit(1);
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
    servizio.sin_port = htons(atoi(argv[2]));

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    listen(socketfd, 10);
    for (;;)
    {
        printf("\n Server in ascolto... \n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &fromlen);
        pid = fork();
        if (pid == 0)
        {
            close(socketfd);

            read(soa, stringa, sizeof(stringa));
            read(soa, &car, sizeof(car));

            EliminaCarattere(stringa, car);

            write(soa, stringa, sizeof(stringa));

            close(soa);
            exit(0);
        }
    }
}
