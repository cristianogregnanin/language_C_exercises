#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char stringa[100], cnt[100];
    int cnttot = 0, p1p2[2], p2p0[2], pid;

    if (argc != 2)
    {
        printf("Argomenti errarti.\n");
        exit(1);
    }

    while (1)
    {

        printf("Che parola vuoi cercare? ");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            printf("Numero di parole trovate: %d\n", cnttot);

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
            execl("/usr/bin/grep", "grep", "-ow", stringa, argv[1], (char *)0);
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
            execl("/usr/bin/wc", "wc", "-l", (char *)0);
            return -1;
        }

        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p0[1]);

        read(p2p0[0], cnt, sizeof(cnt));
        close(p2p0[0]);
        printf("Il file ha %d '%s' \n", atoi(cnt), stringa);
        cnttot = cnttot + atoi(cnt);
    }

    return 0;
}