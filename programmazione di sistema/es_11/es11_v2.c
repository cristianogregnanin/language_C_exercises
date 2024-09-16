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

    int pid, p1p0[2], art_piu_uno;
    char numero[4], articolo_iniziale[12], articolo_finale[12], argomento_grep[50], buff[1];
    pipe(p1p0);
    while (1)
    {
        printf("Inserisci il numero dell'articolo che vuoi ricercare:\n");
        scanf("%s", numero);
        if (strcmp(numero, "esci") == 0)
        {
            close(p1p0[0]);
            close(p1p0[1]);
            exit(1);
        }
        pid = fork();
        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            sprintf(articolo_iniziale, "ART. %s.", numero);
            art_piu_uno = atoi(numero) + 1;
            sprintf(articolo_finale, "ART. %d.", art_piu_uno);
            sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
            execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
            return -1;
        }
        close(p1p0[0]);
        while(read(p1p0[1], &buff, sizeof(buff))>0)
        {
            printf("%s",buff);
        }
        close(p1p0[1]);
    }
    return 0;
}
