#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int pid, p1p2[2];
    char ricercato[10];

    while(1)
    {
        pipe(p1p2);
        pid = fork();
        if(pid == 0)
        {
            close(p1p2[0]);

            printf("Inserisci il numero dell’articolo che vuoi ricercare:\n");
            scanf("%s", ricercato);
            write(p1p2[1], ricercato, sizeof(ricercato));

            close(p1p2[1]); 
            exit(1);
        }
        wait(&pid);

        pid = fork();
        if(pid == 0)
        {
            char articoloIniziale[50];
            char articoloFinale[50];
            char argomentoGrep[200];

            close(p1p2[1]);
            read(p1p2[0], ricercato, sizeof(ricercato));
            close(p1p2[0]);

            if(strcmp(ricercato, "esci") == 0)
            {
                return -1;
            }
            
            if (atoi(ricercato) < 1 || atoi(ricercato) > 138)
            {
                printf("Articolo non esistente\n");
                exit(0);
            }
            sprintf(articoloIniziale, "ART. %s.", ricercato);
            sprintf(articoloFinale, "ART. %d.", (atoi(ricercato) + 1));
            sprintf(argomentoGrep, "(?<=%s)(?s).*(?=%s)", articoloIniziale, articoloFinale);
            execl("/usr/bin/grep", "grep", "-z", "-o", "-P", argomentoGrep, argv[1], NULL);
            exit(2);
        }
        wait(&pid);
        close(p1p2[0]);
        close(p1p2[1]);

    }
}

