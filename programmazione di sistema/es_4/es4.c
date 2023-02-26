#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("errore parametri inseriti\n");
        exit(1);
    }

    char stringa[100], contatore[100];
    int totale = 0, pipe1[2], pid;


    
    while (1)
    {

        printf("Inserisci la parola da ricercare: ");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            close(pipe1[0]);
            close(pipe1[1]);
            printf("Numero totale di parole trovate: %d\n", totale);

            return 0;
        }

        pipe(pipe1);
        pid = fork();

        if (pid == 0)
        {
            close(pipe1[0]);
            close(1);
            dup(pipe1[1]);
            close(pipe1[1]);

            execl("/usr/bin/grep", "grep", "-ow", stringa, argv[1], (char *)0);
            return -1;
        }
        
        pid = fork();

        if (pid == 0)
        {
            close(0);
            dup(pipe1[0]);
            close(pipe1[0]);
            close(1);
            dup(pipe1[1]);
            close(pipe1[1]);

            execl("/usr/bin/wc", "wc", "-l", (char *)0);
            return -1;
        }

        read(pipe1[0], contatore, sizeof(contatore));

        printf("Sono state trovate %d '%s' \n", atoi(contatore), stringa);
        totale += atoi(contatore);
    }

    return 0;
}