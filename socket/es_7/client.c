#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio;
    int socketfd, dimvocali, dimconsonanti;
    char consonanti[strlen(argv[3])];
    char vocali[strlen(argv[3])];

    if (argc != 4)
    {
        printf("Numero di argomenti errato\n");
        exit(2);
    }

    memset((char *)&servizio, 0, sizeof(servizio));

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = inet_addr(argv[1]);
    servizio.sin_port = htons(atoi(argv[2]));

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    int dim = sizeof(argv[3]);
    write(socketfd, &dim, sizeof(dim));

    write(socketfd, argv[3], sizeof(argv[3]));

    read(socketfd, &dimconsonanti, sizeof(int));
    read(socketfd, consonanti, dimconsonanti);

    read(socketfd, &dimvocali, sizeof(int));
    read(socketfd, vocali, dimvocali);

    printf("vocali: %s\n", vocali);
    printf("consonanti: %s\n", consonanti);


    close(socketfd);

    return 0;
}