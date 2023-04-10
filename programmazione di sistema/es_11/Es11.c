#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1


int main(int argc, char *argv[])
{
    char articolo_iniziale[18], articolo_finale[18];
    char argomento_grep[56];
    int pid;
    int p1p2[2]; 
    pipe(p1p2);
    pid=fork();
    if (pid == 0)
    {
       
        close(p1p2[0]);
        while (1)
        {

            char ricerca[4];
            printf("Inserisci numero articolo da ricercare : ");
            scanf("%s",ricerca);

            if (strcmp(ricerca, "esci") == 0) 
            {
                close(p1p2[0]);
                close(p1p2[1]);
                printf("Chiusura del programma.");
                exit(0);
            }

            write(p1p2[1], ricerca, sizeof(ricerca));
        }
    }
    pid=fork();
    if (pid == 0) 
    {
        close(p1p2[1]);
        char buff[4];
        read(p1p2[0], &buff, sizeof(buff));

                
        if (atoi(buff) < 1 || atoi(buff) > 32)
        {
            printf("Articolo non esistente.");
            exit(1);
        }
        sprintf(articolo_iniziale, "ART. %d.", atoi(buff));
        sprintf(articolo_finale, "ART. %d.", (atoi(buff) + 1));
        sprintf(argomento_grep, "-P'(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
        execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
        return -1;
    }
    
    close(p1p2[0]);
    close(p1p2[1]);

    return 0;
}