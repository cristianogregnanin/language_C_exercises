#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define NOME_LENGHT 21
#define COGNOME_LENGHT 21
#define TELEFONO_LENGHT 11
#define MAX_LENGHT 100

typedef struct
{
    char nome[NOME_LENGHT];
    char cognome[COGNOME_LENGHT];
    char telefono[TELEFONO_LENGHT];
} Contatto_t;

void scambia(Contatto_t el1, Contatto_t el2)
{
    Contatto_t tmp = el1;
    el1 = el2;
    el2 = tmp;
}

void ordinaRubrica(Contatto_t contatti[MAX_LENGHT], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            if (strcmp(contatti[j].nome, contatti[j + 1].nome) > 0)
            {
                Contatto_t tmp = contatti[j];
                contatti[j] = contatti[j + 1];
                contatti[j + 1] = tmp;
            }
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Argomenti errati!");
        exit(0);
    }

    if (strcmp(argv[1], "-p") != 0)
    {
        printf("Argomenti errati!");
        exit(0);
    }

    struct sockaddr_in server_addr, client_addr;
    int n, soa, socketfd, clientlen = sizeof(client_addr), fd, on = 1;
    Contatto_t contatti[MAX_LENGHT];

    memset((char *)&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(socketfd, 10);

    for (;;)
    {
        printf("\n\nServer in attesa...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&client_addr, &clientlen);

        int pid = fork();
        if (pid == 0)
        {
            close(socketfd);
            read(soa, &n, sizeof(n));
            read(soa, contatti, sizeof(contatti));

            ordinaRubrica(contatti, n);

            write(soa, contatti, sizeof(contatti));

            close(soa);
            exit(0);
        }
    }
}
