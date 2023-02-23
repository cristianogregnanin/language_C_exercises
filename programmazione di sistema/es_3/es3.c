#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("argomenti inseriti errati\n");
        return -1;
    }

    char stringa[100], contatore[100];
    int p1p0[2], totale = 0;
        
    while(1)
    {
        
        printf("Inserisci la stringa da ricercare: ");
        scanf("%s", stringa);

        if(strcmp(stringa, "fine") == 0)
        {
            printf("Programma terminato");
            printf("\nIn tutto sono state trovate %d parole\n", totale);
            return 0;
        }

        pipe(p1p0);
        pid_t pid = fork();
        
        if(pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);

            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0);
            return -1;
        }

        read(p1p0[0], contatore, sizeof(contatore));
        
        printf("Sono stati trovati %d volte la stringa %s\n\n", atoi(contatore), stringa);
        totale += atoi(contatore);
        
    }
}
