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
    int p1p0[2], tot = 0, p1;
    pipe(p1p0);
    while (1)
    {
        printf("Inserisci codice:\n");
        scanf("%s", codice);
        if (strcmp("esci", codice) == 0)
        {
            printf("sono stati trovati: %d insoluti\n", tot);
            exit(0);
        }
        p1 = fork();
        if (p1 == 0)
        {
            close(1);
            dup(p1p0[WRITE]);
            close(p1p0[READ]);
            close(p1p0[WRITE]);

            execl("/bin/grep", "grep", "-c", strcat(codice, " insoluto"), argv[1], NULL);
            return -1;
        }
        if (p1 > 0)
        {
            wait(&p1);
            read(p1p0[READ], stringa, sizeof(stringa));
            printf("Sono stati trovati %d insoluti\n", atoi(stringa));
            tot = tot + atoi(stringa);
        }
        if (p1 < 0)
        {
            printf("Errore durante la generazione del figlio");
        }
    }
    return 0;
}
