#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p3[2], p3p0[2], pid;
    char buffer, *puntatore, strimporto[100];
    double tot = 0;
    pipe(p1p2);
    pipe(p2p3);
    close(p1p2[1]);
    close(p1p2[0]);
    pipe(p3p0);
    close(p2p3[0]);
    close(p2p3[1]);
    close(p3p0[1]);
    close(p3p0[0]);

    pid = fork(); // primo figlio per il comando traceroute
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/sbin/traceroute", "traceroute", argv[1], NULL);
        exit(1);
    }

    pid = fork(); // secondo figlio per il comando awk
    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        close(p2p3[0]);
        close(1);
        dup(p2p3[1]);
        close(p2p3[1]);
        execl("/usr/bin/awk", "awk", "{print $4}",NULL );
        exit(1);
    }

    pid = fork(); // terzo figlio per il comando tail
    if (pid == 0)
    {
        close(p2p3[1]);
        close(0);
        dup(p2p3[0]);
        close(p2p3[0]);
        close(p3p0[0]);
        close(1);
        dup(p3p0[1]);
        close(p3p0[1]);
        execl("/usr/bin/tail", "tail", "-n", "+2", NULL);
        exit(1);
    }

    while (read(p3p0[0], buffer, sizeof(buffer)) > 0) // while che legge fino a che non finiscono le parole
    {
        strncat(strimporto, &buffer, sizeof(buffer)); // concateno la stringa
        if (buffer == '\n')                           // fino a che non è diversa da /n
        {
            printf("Tempo parziale: %s", strimporto);
            tot += +strtod(strimporto, &puntatore);
            strimporto[0] = '\0';
        }
    }

    printf("\nIl tempo totale impiegato è: %.2lf ms\n", tot);
    return 0;
}