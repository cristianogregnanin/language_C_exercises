#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <sys/wait.h>

#include <stdbool.h>

#define MAX 50000

bool FineProgramma(int conta, char stringa[])

{

    printf("Parola: ");

    scanf("%s", stringa);

    return strcmp(stringa, "fine") == 0;

}

int main(int argc, char *argv[])

{

    if (argc != 2)

    {

        printf("Numero parametri errato\n");

        exit(1);

    }

    char stringa[MAX], conta_stringa[MAX];

    int p1p0[2], conta_totale = 0;

    pipe(p1p0);

    while (!FineProgramma(conta_totale, stringa))

    {

        int pid = fork();

        if (pid == 0)

        {

            close(p1p0[0]);

            close(1);

            dup(p1p0[1]);

            close(p1p0[1]);

            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0);

            return -1;

        }

        read(p1p0[0], conta_stringa, MAX);

        printf("Il file ha %d stringhe: '%s' \n", atoi(conta_stringa), stringa);

        conta_totale += atoi(conta_stringa);

    }

    close(p1p0[0]);

    close(p1p0[1]);

    printf("Trovate le seguenti parole: %d\n", conta_totale);

    return 0;

}




