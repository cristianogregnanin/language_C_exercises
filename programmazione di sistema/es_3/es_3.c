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
    int p1p0[2], cnttot = 0;

    pipe(p1p0);
    do
    {
        printf("Che parola vuoi cercare? ");
        scanf("%s", stringa);
        int pid = fork();

        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);

            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1],NULL);
            printf("Errore nel lanciare la grep");
        }
        read(p1p0[0], cnt, sizeof(cnt));
        printf("Il file ha %d '%s' \n", atoi(cnt), stringa);
        cnttot += atoi(cnt);

    } while (strcmp(stringa, "fine") != 0);
    close(p1p0[1]);
    close(p1p0[0]);
    printf("Numero di parole trovate: %d\n", cnttot);
    exit(1);

    return 0;
}