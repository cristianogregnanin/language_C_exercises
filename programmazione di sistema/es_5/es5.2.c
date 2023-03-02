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
        printf("Argomenti errati. Inserire come primo argomento il nome di un file\n");
        exit(0);
    }
    char stringa[1000], codice[5];
    int p1p2[2], tot = 0, pid, p2p0[2];

    pipe(p1p2);
    pipe(p2p0);
    while (1)
    {
        printf("Inserisci codice:\n");
        scanf("%s", codice);
    
        if (strcmp("esci", codice) == 0)
        {
            printf("sono stati trovati: %d insoluti\n", tot);
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

            execl("/bin/grep", "grep", codice, argv[1], NULL);
            return -1;
        }

        pid = fork();
        if (pid == 0)
        {

            close(p1p2[WRITE]);
            close(p2p0[READ]);

            close(READ);
            dup(p1p2[READ]);
            close(p1p2[READ]);

            close(WRITE);
            dup(p2p0[WRITE]);
            close(p2p0[WRITE]);

            execl("/bin/grep", "grep", "-c", "insoluto", NULL);
            return -1;
        }

        read(p2p0[READ], stringa, sizeof(stringa));
        printf("Sono stati trovati %d insoluti\n", atoi(stringa));
        tot = tot + atoi(stringa);

        if (pid < 0)
        {
            printf("Errore durante la generazione del figlio");
        }
    }

    return 0;
}