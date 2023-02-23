#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    char stringa[100], stringa2[100];
    int pid, cnttot = 0;
    int tubo[2];

    if (argc < 2)
    {
        printf("valori sbagliati\n");
        exit(1);
    }
    pipe(tubo);
    while (1)
    {

        printf("inserisci una stringa\n");
        scanf("%s", stringa);
        if (strcmp(stringa, "fine") == 0)
        {
            close(tubo[1]);
            close(tubo[0]);
            printf("numero parole trovate %d", cnttot);
            exit(1);
        }
        pid = fork();

        if (pid == 0)
        {
            close(tubo[0]);
            close(1);
            dup(tubo[1]);
            close(tubo[1]);
            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], NULL);
            return -1;
        }
        wait(&pid);
        read(tubo[0], stringa2, sizeof(stringa2));
        printf("la parola %s è stata trovata %d volte\n", stringa, atoi(stringa2));
        cnttot += atoi(stringa2);
    }
}