#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <string.h>
    int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti errato.");
        exit(1);
    }

    int pid, p1p0[2];
    char numero[4], articolo_iniziale[10], articolo_finale[10], argomento_grep[100];
    while (1)
    {
        pipe(p1p0);
        printf("Inserisci il numero dell'articolo che vuoi ricercare:\n");
        scanf("%s", numero);
        pid = fork();
        if (pid == 0)
        {
            close(p1p0[0]);
            if (strcmp(numero, "esci") == 0)
            {
                close(p1p0[0]);
                close(p1p0[1]);
                exit(1);
            }
            else
            {
                close(p1p0[1]);
                int art_piu_uno;
                sprintf(articolo_iniziale, "ART. %s.", numero);
                art_piu_uno = atoi(numero) + 1;
                sprintf(articolo_finale, "ART. %d.", art_piu_uno);
                sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
                execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
                return -1;
            }
        }
       printf("%s",articolo_iniziale);

        wait(&pid);
        wait(&pid);
        close(p1p0[0]);
        close(p1p0[1]);

    }
    return 0;
}