#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#define READ 0
#define WRITE 1
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p3[2], p3p0[2], pid;
    char carattere, stringrisult[100];
    double risultato;
    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[READ]);
        close(WRITE);
        dup(p1p2[WRITE]);
        close(p1p2[WRITE]);

        execl("/usr/sbin/cat", "cat", argv[1], NULL);
        return -1;
    }
    pipe(p2p3);
    pid = fork();
    if (pid == 0)
    {
        /*
         close(p2p3[READ]);
        close(WRITE);
        dup(p2p3[WRITE]);
        close(p2p3[WRITE]);

        close(p1p2[WRITE]);
        close(READ);
        dup(p1p2[READ]);
        close(p1p2[READ]);
        */
        close(p2p3[WRITE]);
        close(READ);
        dup(p2p3[READ]);
        close(p2p3[READ]);

        close(p3p0[READ]);
        close(WRITE);
        dup(p3p0[WRITE]);
        close(p3p0[WRITE]);

        execl("/usr/bin/awk", "awk", "{print $5}", NULL);
        return -1;
    }
    close(p1p2[WRITE]);
    close(p1p2[READ]);
    pipe(p3p0);
    pid = fork();
    if (pid == 0)
    {
        close(p2p3[READ]);
        close(p2p3[WRITE]);

        close(WRITE);
        dup(p3p0[WRITE]);
        close(p3p0[WRITE]);

        close(p2p3[WRITE]);
        close(READ);
        dup(p2p3[READ]);
        close(p2p3[READ]);

        execl("/usr/bin/tail", "tail", "-n", "+2", NULL);
    }
    close(p2p3[READ]);
    close(p2p3[WRITE]);
    close(p3p0[WRITE]);

    while (read(p3p0[READ], carattere, sizeof(carattere)) > 0)
    {
        strncat(stringrisult, &carattere, sizeof(carattere));
        if (carattere == '\n')
        {
            printf("Tempo parziale: %s", stringrisult);
            risultato = risultato + strtod(stringrisult, NULL);
            stringrisult[0] = '\0';
        }
    }
    close(p3p0[0]);
    printf("\nIl tempo totale impiegato è: %f ms\n", risultato);
    return 0;

    return 0;
}
