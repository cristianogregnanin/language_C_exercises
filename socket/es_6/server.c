#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

void contaOccorrenze(char testo[100][100], char stringa[], int *cnt, int numParole)
{
    for (int j = 0; j < numParole; j++)
    {
        if (strcmp(testo[j], stringa) == 0)
            (*cnt)++;
    }
}

int main(int argc, char *argv[])
{
    char stringa[20];
    char testo[100][100];
    int numParole = 0;
    int cnt = 0;
    if (argc != 3)
    {
        printf("Numero di argomenti errato\n");
        exit(2);
    }

    if (strcmp(argv[1], "-p") != 0)
    {
        printf("Errore parametro\n");
        exit(2);
    }
    struct sockaddr_in server_addr, client_addr;
    int soa, socketfd, client_len, fd, on = 1, fromlen = sizeof(server_addr);

    struct hostent *host;
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[2]));

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(socketfd, 10);
    for (;;)
    {
        printf("\n\nServer in ascolto...\n");
        fflush(stdout);
        cnt = 0;

        soa = accept(socketfd, (struct sockaddr *)&client_addr, &fromlen);

        host = gethostbyaddr((char *)&client_addr.sin_addr, sizeof(client_addr.sin_addr), AF_INET);
        printf("\n\nStabilita la connessione con il client %s \n", host->h_name);

        read(soa, testo, sizeof(testo));
        read(soa, &numParole, sizeof(numParole));
        read(soa, stringa, sizeof(stringa));

        contaOccorrenze(testo, stringa, &cnt, numParole);

        write(soa, &cnt, sizeof(cnt));

        close(soa);
    }

    return 0;
}