#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    double totale = 0;
    char buffer[1], *ptr, strimporto[100];

    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/awk", "awk", "{print $3}", (char *)0);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);
    close(p2p0[1]);

    while (read(p2p0[0], buffer, sizeof(buffer)) > 0)
    {

        strncat(strimporto, &buffer[0], sizeof(buffer[0]));
        if (buffer[0] == '\n')
        {
            printf("ricevuto importo dalla pipe p2p0: %s", strimporto);
            totale = totale + strtod(strimporto, &ptr);
            strimporto[0] = '\0';
        }
    }

    close(p2p0[0]);
    printf("\nIl totale delle fatture è: %.2lf\n", totale);
    return 0;
}