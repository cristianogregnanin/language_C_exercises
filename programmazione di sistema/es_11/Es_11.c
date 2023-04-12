#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero di argomenti errati");
        exit(1);
    }

    int pid, p1p2[2];
    char stringa[10], argomento_grep[1000], articolo_iniziale[100], articolo_finale[100];

    pipe(p1p2);
    
    pid = fork();
    if (pid == 0) //p1
    {
        close(p1p2[0]);
        while (1)
        {
            printf("Inserisci un numero di articolo (o 'esci' per uscire)\n");
            scanf("%s", stringa);
            if (strcmp(stringa, "esci") == 0)
            {
                printf("Esecuzione terminata, esco\n");
                exit(0);
            }
            if (atoi(stringa) < 1)
            {
                printf("Numero di articolo non valido\n");
            }
            else
            {
                sprintf(articolo_iniziale, "ART. %s.", stringa);
                sprintf(articolo_finale, "ART. %d.", atoi(stringa)+1);
                sprintf(argomento_grep, "-P '(?<= %s)(?s).*(?= %s)'", articolo_iniziale, articolo_finale);
                write(p1p2[1], argomento_grep, strlen(argomento_grep)+1);
            }
        }        
    }

    close(p1p2[1]);

    pid = fork();
    if (pid == 0) //p2
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
    }
    
    close(p1p2[0]);
    
    return 0;
}