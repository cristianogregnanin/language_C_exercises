#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Parametri errati \n");
        return -1;
    }
    pid_t pid;
    char art[20], articolo_iniziale[30], articolo_finale[100], argomento_grep[200], articolo_Nuovo[200];
    int p0p1[2];

    while (1)
    {
        pipe(p0p1);
        printf("Inserisci articolo \n");
        scanf("%s", art);
        if (strcmp(art, "esci") == 0)
        {
            close(p0p1[1]);
            close(p0p1[0]);
            return 0;
        }
        pid = fork();
        if (pid == 0)
        {
            close(p0p1[0]);
            close(1);
            dup(p0p1[1]);
            // close(p0p1[1]);
            sprintf(articolo_iniziale, "ART. %s.", art);
            printf("%s \n", articolo_iniziale);
            sprintf(articolo_finale, "ART. %d.", atoi(art) + 1);
            printf("%s \n", articolo_finale);
            sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
            printf("%s \n", argomento_grep);
            execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
            return -1;
        }
        read(p0p1[0], articolo_Nuovo, sizeof(articolo_Nuovo));
        write(1, articolo_Nuovo, sizeof(articolo_Nuovo));
    }
    close(p0p1[0]);
    close(p0p1[1]);
    return 0;
}