#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
int main(int argc, char *argv[])
{

    int p1p2[2];
    int p2p0[2];

    int contoParole;
    int p1, p2;

    char Str_parole[10] = {0}; // Inizializza con zeri

    if (argc < 2)
    {
        printf("Numero di argomenti insufficiente");
        return -1; // Aggiungi un return per uscire
    }

    pipe(p1p2);

    p1 = fork();

    if (p1 == 0)
    {

        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL); // Correggi il percorso di 'cat'

        return -1;
    }

    close(p1p2[1]);

    pipe(p2p0);

    p2 = fork();

    if (p2 == 0)
    {

        char carattere;
        int parole = 0;

        while (read(p1p2[0], &carattere, sizeof(carattere)))
        {
            if (carattere == ' ' || carattere == '\n') // Conta anche i ritorni a capo
            {
                parole++;
            }
        }

        sprintf(Str_parole, "%d", parole);

        write(p2p0[1], Str_parole, strlen(Str_parole) + 1); // Includi il terminatore null

        close(p2p0[1]);
        exit(0);
    }

    close(p1p2[0]);

    read(p2p0[0], Str_parole, sizeof(Str_parole)); // Usa la dimensione fissa di Str_parole

    close(p2p0[0]);
    close(p2p0[1]);

    wait(&p1);
    wait(&p2);

    printf("Il file %s contiene %s parole\n", argv[1], Str_parole); // Aggiungi un newline per chiarezza

    return 0;
}