#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int pid;
    int p1p2[2]; 
    char articoloDaRicercare[10];

    char articoloIniziale[100];
    char articoloFinale[100];
    char argomentoGrep[100];

    if (argc != 2)
    {
        printf("Numero argomenti errato");
        exit(0);
    }

    pid = fork();

    if (pid== 0)// P1
    {
        pipe(p1p2);
        while (1)
        {
            close(p1p2[0]); 
            printf("Inserisci il numero dell'articolo da ricercare:  ");
            scanf("%s",articoloDaRicercare);

            if (strcmp(articoloDaRicercare, "esci") == 0) // se scrivo esci il programma termina
            {
                close(p1p2[1]);
                exit(0);
            }

            write(p1p2[1], articoloDaRicercare, sizeof(articoloDaRicercare));       //scrivo l'articolo nella pipe
        }
    }

    pid = fork();
    if (pid == 0) // P2
    {
        close(p1p2[1]);

        read(p1p2[0], articoloDaRicercare, 5);       //Leggo ciò che ho scritto nella pipe
  
        if (atoi(articoloDaRicercare) < 1 || atoi(articoloDaRicercare) > 32)        // Controllo il numero degli articoli
        {
            printf("L'articolo non esiste");
            exit(1);                                                                //se l'articolo non esiste il programma termina
        }

        sprintf(articoloIniziale, "ART. %d.", atoi(articoloDaRicercare));
        sprintf(articoloFinale, "ART. %d.", (atoi(articoloDaRicercare)));

        execl("usr/bin/grep", "grep", "-z", "-o", argomentoGrep, argv[1], NULL);
        return -1;
    }

    return 0;
}