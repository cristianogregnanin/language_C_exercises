#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    char ArticoloFull[100];
    char argomentoGrep[100];	
    char RicercaArticolo[10];
    char ArticoloVuoto[100];
    int pid;
    int p1p2[2];
    pid = fork();
    if (argc != 2)
    {
        printf("argomenti errati\n");
        exit(0);
    }
    if (pid== 0)
    {
        pipe(p1p2);
        while (1)
        {
            close(p1p2[0]); 
            printf("Inserire Numero articolo:  ");
            scanf("%s",RicercaArticolo);

            if (strcmp(RicercaArticolo, "esci") == 0) 
            {
                close(p1p2[1]);
                exit(0);
            }

            write(p1p2[1], RicercaArticolo, sizeof(RicercaArticolo));       
        }
    }
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        execl("/usr/bin/grep", "grep", "-z", "-o", ArticoloVuoto, argv[1], NULL);
        return -1;
    }
    return 0;
}