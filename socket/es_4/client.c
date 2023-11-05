#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void leggiFile(char nomeFile[], char testo[100][100], int *numParole)
{
    FILE *stream;

    if ((stream = fopen(nomeFile, "r")) == NULL)
    {
        printf("errore nell'apertura del file input\n");
        exit(3);
    }
    for (numParole; !feof(stream); (*numParole)++)
    {
        fscanf(stream, "%s\n", testo[*numParole]);
    }
    fclose(stream);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio;
    char stringa[20], testo[100][100];
    int cnt = 0, numParole = 0, socketfd;

    if (argc != 5)
    {
        printf("Numero di argomenti errato\n");
        exit(2);
    }

    memset((char *)&servizio, 0, sizeof(servizio));

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = inet_addr(argv[1]);
    servizio.sin_port = htons(atoi(argv[2]));

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    leggiFile(argv[3], testo, &numParole);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    strcpy(stringa, argv[4]);
    write(socketfd, testo, sizeof(testo));
    write(socketfd, &numParole, sizeof(numParole));
    write(socketfd, stringa, sizeof(stringa));
    read(socketfd, &cnt, sizeof(cnt));
    printf("La parola %s e' presente %d volte\n", stringa, cnt);
    close(socketfd);

    return 0;
}