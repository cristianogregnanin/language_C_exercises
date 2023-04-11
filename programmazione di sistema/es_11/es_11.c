#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define DIM 500
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Parametri errati \n");
        return -1;
    }
    pid_t pid;
    char art[DIM], articolo_iniziale[DIM], articolo_finale[DIM], argomento_grep[DIM], articolo_Nuovo[DIM];
    int p1p2[2];

    pid = fork();
    if (pid == 0)
    {
        while (1)
        {
            pipe(p1p2);
            printf("Inserisci articolo \n");
            scanf("%s", art);
            if (strcmp(art, "esci") == 0)
            {
                close(p1p2[0]);
                close(p1p2[1]);
                return 0;
            }
            int scrivi;
            scrivi = write(p1p2[1], art, strlen(art));
            close(p1p2[1]);
            pid = fork();
            if (pid == 0)
            {
                read(p1p2[0], articolo_Nuovo, scrivi);
                close(p1p2[0]);
                sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
                sprintf(articolo_iniziale, "ART. %d.", atoi(articolo_Nuovo));
                sprintf(articolo_finale, "ART. %d.", atoi((articolo_Nuovo) + 1));
                execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
                return -1;
            }
        }
    }
    close(p1p2[0]);
    close(p1p2[1]);
    return 0;
}