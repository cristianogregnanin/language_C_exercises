#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char stringa[1000];
    int channel[2];
    pipe(channel);
    char cnt[1000];
    int cnttot = 0;

    do
    {
        printf("Che parola vuoi cercare? ");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") != 0)
        {
            int pid = fork();

            if (pid == 0)
            {
                close(channel[0]);
                close(1);
                dup(channel[1]);
                close(channel[1]);
                execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0);
                return -1;
            }
            wait(&pid);
            read(channel[0], cnt, sizeof(cnt));
            printf("Il file ha %d '%s' \n", atoi(cnt), stringa);
            cnttot += atoi(cnt);
        }
    } while (strcmp(stringa, "fine") != 0);

    printf("Numero di parole trovate: %d\n", cnttot);
    return 0;
}