#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p1p2[2];
    int p2p0[2];
    int pid;
    char articolo_iniziale[30];
    char articolo_finale[30];
    char argomento_grep[30]
    char str[50];

    if (argc != 2)
    {
        printf("Numero di argomenti sbagliato.");
        exit(0);
    }

    pipe(p1p2);
    pid = fork();

    if (pid == 0)
    {
       do{

            printf("Inserisci il numero dell'articolo che vuoi ricercare: ");
            scanf("%s", str);

            sprintf(articolo_iniziale, "ART. %d.", atoi(str));
            sprintf(articolo_finale, "ART. %d.", atoi(str) + 1);

            write(p1p2[1], articolo_iniziale, strlen(articolo_iniziale));
            write(p1p2[1], articolo_finale, strlen(articolo_finale));

       }while (strcmp(str, "esci") != 0);
    }


    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/grep", "grep", "-z", "-o", articolo_iniziale, argv[1], NULL);
        return -1;
    }

    return 0;
}