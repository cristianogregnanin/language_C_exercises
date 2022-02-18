#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero parametri errato\n");
        exit(1);
    }

    char stringa[1000], cnt[1000];
    int piped[2], cnttot = 0;

    pipe(piped);
    while (1)
    {
        printf("Che parola vuoi cercare? ");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            close(piped[1]);
            close(piped[0]);
            printf("Numero di parole trovate: %d\n", cnttot);
            exit(1);
        }

        int pid = fork();

        if (pid == 0)
        {
            close(piped[0]);
            close(1);
            dup(piped[1]);
            close(piped[1]);

            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0);
            return -1;
        }
        read(piped[0], cnt, sizeof(cnt));
        printf("Il file ha %d '%s' \n", atoi(cnt), stringa);
        cnttot += atoi(cnt);
    }

    return 0;
}