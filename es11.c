#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pid, p1p2[2]; // nella pipe salvo l'articolo da ricercare
    char articolo[5]; // articolo formato da 5 caratteri ART. X.
    char articolo_iniziale[15];
    char articolo_finale[15];
    char argomento_grep[80];

    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    pid = fork();
    if (pid == 0)
    {
        while (1)
        {
            pipe(p1p2);
            close(p1p2[0]); // chiudo canale di lettura

            printf("Inserisci l'articolo che vuoi ricercare");
            scanf("%s", articolo);
            if (strcmp(articolo, "esci") == 0)
            {
                close(p1p2[1]);
                exit(0);
            }

            write(p1p2[1], articolo, sizeof(articolo));

            if (pid == 0)
            {
                close(p1p2[1]);
                read(p1p2[0], articolo, 5);
                execl("/usr/bin/grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
            }

            sprintf(articolo_iniziale, "ART. %d.", atoi(articolo));
            sprintf(articolo_finale, "ART. %d.", atoi((articolo) + 1));
            sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)", articolo_iniziale, articolo_finale);

            

            return -1;
        }
    }
    return 0;
}