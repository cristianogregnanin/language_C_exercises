#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100
int main(int argc, char *argv[])
{
    int pid, p1p0[2], totale = 0;
    char parola[MAX];
    char conta[MAX];
    if (argc != 2)
    {
        printf("Numero di elementi errato!\n\n");
        exit(1);
    }

    pipe(p1p0);
    while (strcmp(parola, "fine") != 0)
    {

        printf("\nInserire la parola da ricercare: ");
        scanf("%s", parola);

        pid = fork();
        if (pid == 0)
        {
            // chiudo file descriptor superflui
            close(p1p0[0]);
            // scrivo su pipe
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            // eseguo comando grep -c per ricercare e contare le parole sul file in argv[1]
            execl("/usr/bin/grep", "grep", "-c", parola, argv[1], NULL);
            return -1;
        }
        /*
        leggo da pipe
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);
        */
        read(p1p0[0], conta, sizeof(conta));
        totale += atoi(conta);
        printf("\nNel file '%s' la parola '%s' è ripetuta %s volte. \n", argv[1], parola, conta);
    }

    close(p1p0[1]);
    close(p1p0[0]);
    printf("\nIl numero totale di parole trovate è: %d.\n\n", totale);
    return 0;
}
