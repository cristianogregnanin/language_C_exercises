#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("errore\n");
        return -1;
    }
    int pid, p1p2[2];
    char numeroart[4];
    char buffer[1];
    char argomento_grep[100];
    char articolo_iniziale[15], articolo_finale[15];

    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        while (1)
        {
            printf("inserisci il numero dell'articolo\n");
            scanf("%d", &numeroart);
            if (strcmp(numeroart, "esci") == 0)
            {
                exit(0);
            }
            else
            {
                write(p1p2[1], &numeroart, sizeof(numeroart));
            }
        }
    }

    pid = fork();
    if (pid == 0)
    {
        read(p1p2[0], &buffer, sizeof(buffer));

        sprintf(articolo_iniziale, "ART. %d.", atoi(ricerca));
        sprintf(articolo_finale, "ART. %d.", (atoi(ricerca) + 1));
        sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)", articolo_iniziale, articolo_finale);

        execl("usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
        return -1;
    }
    wait(&pid);
    return 0;
}