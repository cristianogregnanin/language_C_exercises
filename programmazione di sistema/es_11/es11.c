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

    int pid;

    char articolo[4], articolo_iniziale[10], articolo_finale[10], argomento_grep[100];
    int p1p0[2];

    while (1)
    {

        pipe(p1p0);
        printf("Inserisci il numero dell’articolo che vuoi ricercare:\n");
        scanf("%s", articolo);

        if (strcmp(articolo, "Esci") == 0)
        {
            exit(0);
        }

        sprintf(articolo_iniziale, "ART. %d.", atoi(articolo));
        sprintf(articolo_finale, "ART. %d.", atoi(articolo) + 1);
        sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);

        pid = fork();

        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
            return -1;
        }

        wait(&pid);

        close(p1p0[1]);

        int nRead;
        char buffer[100];

        while (nRead = read(p1p0[0], buffer, strlen(buffer)) > 0)
        {
            write(1, buffer, nRead);
        }

        close(p1p0[0]);
        printf("\n\n");
    }
}
