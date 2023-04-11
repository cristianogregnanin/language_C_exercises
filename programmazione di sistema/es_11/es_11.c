#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errone nell'inserimento dei parametri\n");
        return -1;
    }

    int pid, p1p2[2];

    pipe(p1p2);
    pid = fork();

    if (pid == 0)
    {
        char articolo[4];

        while (1)
        {
            printf("Inserisci il numero dell’articolo che vuoi ricercare:\n");
            scanf("%s", articolo);

            if (strcmp(articolo, "Esci") == 0)
            {
                close(p1p2[0]);
                close(p1p2[1]);
                exit(0);
            }

            int nWrite = write(p1p2[1], articolo, strlen(articolo));

            pid = fork();
            if (pid == 0)
            {
                close(p1p2[1]);
                char argomento_grep[100], articolo_iniziale[10], articolo_finale[10], tmp[4];

                read(p1p2[0], tmp, nWrite);
                close(p1p2[0]);

                sprintf(articolo_iniziale, "ART. %d.", atoi(tmp));
                sprintf(articolo_finale, "ART. %d.", atoi(tmp) + 1);
                sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);

                execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
                return -1;
            }

            wait(&pid);
            printf("\n\n");
        }
    }

    wait(&pid);
    close(p1p2[0]);
    close(p1p2[1]);
    return 0;
}
