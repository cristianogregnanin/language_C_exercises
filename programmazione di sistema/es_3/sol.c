#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100

int main(int argc, char *argv[])
{
    int loop = 1;
    char stringa[MAX];
    char conta[MAX];
    int contaTot = 0;
    int p1p0[2];

    pipe(p1p0);
    while (loop)
    {
        printf("Inserisci la stringa:\n");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            close(p1p0[1]);
            close(p1p0[0]);
            printf("Il totale è: %d\n", contaTot);
            loop = 0;
        }

        int pid = fork();

        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);

            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], NULL);
        }
        read(p1p0[0], conta, strlen(conta));
        printf("In questo file ci sono %s volte %s \n", conta, stringa);
        contaTot += atoi(conta);
    }

    return 0;
}
