#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], pid;

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        int buffer[50];
        char stringa[50];
        printf("Inserisci il numero dell’articolo che vuoi ricercare:\n");
        scanf("%s", stringa);
        write(p1p2[1], stringa, sizeof(buffer));
        exit(0);
    }
    char articolo_iniziale[100], articolo_finale[100];
    if (pid == 0)
    {
        close(p1p2[1]);

        read(p1p2[0], stringa, sizeof(stringa));
        sprintf(argomento_grep, "'(?<=%s)(?s).*", stringa);
        sprintf(articolo_finale, "(?=%d)'", atoi(stringa) + 1);
        strncat(argomento_grep, articolo_finale, sizeof(articolo_finale));
        execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
        exit(0);
    }

    close(p1p2[0]);
    close(p1p2[1]);

    return 0;
}