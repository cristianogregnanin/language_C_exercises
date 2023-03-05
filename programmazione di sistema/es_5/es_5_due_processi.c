/*
Questa soluzione usa due processi che lanciano grep
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
    char conta[10], codice[50];
    int p1p2[2], p2p0[2];
    int pid, contaTOT = 0;

    pipe(p1p2);
    pipe(p2p0);
    while (1)
    {
        printf("Inserisci codice: ");
        scanf("%s", codice);

        if (strcmp("esci", codice) == 0)
        {
            printf("Trovati %d insoluti in tutte le ricerche.\n", contaTOT);
            close(p1p2[READ]);
            close(p1p2[WRITE]);
            close(p2p0[READ]);
            close(p2p0[WRITE]);
            exit(0);
        }

        pid = fork();
        if (pid == 0)
        {
            close(p2p0[READ]);
            close(p2p0[WRITE]);

            close(p1p2[READ]);
            close(WRITE);
            dup(p1p2[WRITE]);
            close(p1p2[WRITE]);

            execl("/bin/grep", "grep", codice, "file5pipe.txt", NULL);
            return -1;//stderr
        }
        pid = fork();
        if (pid == 0)
        {
            close(p1p2[WRITE]);
            close(p2p0[READ]);

            close(READ);//stdin
            dup(p1p2[READ]);
            close(p1p2[READ]);

            close(WRITE);//stdout
            dup(p2p0[WRITE]);
            close(p2p0[WRITE]);

            execl("/bin/grep", "grep", "-c", "insoluto", NULL);
            return -1;//sterr
        }

        read(p2p0[READ], conta, sizeof(conta));
        printf("Trovati %d insoluti\n", atoi(conta));
        contaTOT += atoi(conta);
    }
}
