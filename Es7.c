#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int p1p2[2], p2p3[2], p3p0[2], pid;
    char stringa, impTot[200], *tmp;
    double TempoTot;

    if (argc != 2)
    {
        printf("Numero argomenti sbagliati");
        exit(1);
    }

    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/sbin/traceroute", "traceroute", argv[1], NULL);
        return -1;
    }

    pipe(p2p3);
    pid = fork();
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
        execl("/usr/bin/awk", "awk", "{print $4}", NULL);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);

    pipe(p3p0);
    pid = fork();
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
        return -1;
    }

    close(p2p3[0]);
    close(p2p3[1]);
    close(p3p0[1]);

    while (read(p3p0[0], &stringa, sizeof(stringa)) > 0)
    {
        strncat(impTot, &stringa, sizeof(stringa));
        if (stringa == '\n')
        {
            printf("Il tempo parziale impiegato è: %s", impTot);
            TempoTot = TempoTot + strtod(impTot, &tmp);
            impTot[0] = '\0';
        }
    }

    close(p3p0[0]);
    printf("\nIl tempo totale impiegato è: %.2lf ms\n", TempoTot);
    return 0;
    
}
