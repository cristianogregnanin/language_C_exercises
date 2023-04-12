#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("numero di argomenti errato");
        return -1;
    }

    int pid, p1p2[2];
    char articolo[4];

    pipe(p1p2);
    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        while (1)
        {
            printf("Inserisci il numero dell’articolo che vuoi ricercare:\n");
            scanf("%s", articolo);
            if (articolo == "esci")
            {
                close(p1p2[0]);
                close(p1p2[1]);
                return 0;
            }
            write(p1p2[1], articolo, strlen(articolo));
        }
    }

    pid == fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        char argomento_grep;

        sprintf(argomento_grep, "-z -o -P '(?<=^%s)(?s).*(?=^%s)' %s", p1p2[0], p1p2[0]+1);
        execl("usr/bin/grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
        return -1;
    }
}