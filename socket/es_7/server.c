#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

void controllaInput(int argc, char *argv[])
{
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
}

void separaVocali(char str[], char vocali[], char consonanti[])
{
    int i, k = 0, j = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o' || str[i] == 'e')
        {
            vocali[k] = str[i];
            k++;
        }
        else
        {
            consonanti[j] = str[i];
            j++;
        }
    }
}

int main(int argc, char *argv[])
{

    controllaInput(argc, argv);

    struct sockaddr_in server_addr, client_addr;
    int soa, socketfd, on = 1, fromlen = sizeof(server_addr), dim;

    struct hostent *host;
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[2]));

    char stringa[100], vocali[100], consonanti[100];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(socketfd, 10);
    for (;;)
    {
        printf("\n\nServer in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&client_addr, &fromlen);

        read(soa, &dim, sizeof(int));
        read(soa, stringa, dim);

        separaVocali(stringa, vocali, consonanti);

        printf("vocali: %s\n", vocali);
        printf("consonanti: %s\n", consonanti);

        int dimconsonanti = strlen(consonanti);
        write(soa, &dimconsonanti, sizeof(int));
        write(soa, consonanti, sizeof(consonanti));

        int dimvocali = strlen(vocali);
        write(soa, &dimvocali, sizeof(int));
        write(soa, vocali, sizeof(vocali));

        close(soa);
    }

    return 0;
}