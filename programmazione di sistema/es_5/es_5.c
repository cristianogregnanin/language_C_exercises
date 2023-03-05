#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
    char conta[10], codice[500];
    int p1p0[2], contaTOT = 0, pid;

    pipe(p1p0);
    while (1)
    {
        printf("Inserisci codice:");
        scanf("%s", codice);

        if (strcmp("esci", codice) == 0)
        {
            printf("sono stati trovati: %d insoluti\n", contaTOT);
            close(p1p0[READ]);
            close(p1p0[WRITE]);
            exit(0);
        }

        pid = fork();
        if (pid == 0)
        {
            close(p1p0[READ]);
            close(WRITE);
            dup(p1p0[WRITE]);
            close(p1p0[WRITE]);

            execl("/bin/grep", "grep", "-c", strcat(codice, " insoluto"), argv[1], NULL);
            return -1;
        }

        read(p1p0[READ], conta, sizeof(conta));
        printf("Sono stati trovati %d insoluti\n", atoi(conta));
        contaTOT += atoi(conta);
    }
}
