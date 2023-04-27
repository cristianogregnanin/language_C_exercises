#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int pid, p1p0[2];
    char stringa[10];
    char argomento_grep[120];
    char articolo_iniziale[50];
    char articolo_finale[50];
    char buff[10000];
    int y, nread = 0;
    if (argc != 2)
    {
        printf("Argomenti errati");
        return -1;
    }
    while (1)
    {
        printf("Inserire il numero dell'artiolo (esci per terminare):");
        scanf("%s", stringa);
        if (strcmp(stringa, "esci") == 0)
        {
            printf("Fine");
            wait(&pid);
            close(p1p0[1]);
            close(p1p0[0]);
            return 0;
        }
        sprintf(articolo_iniziale, "ART. %s.", stringa);
        y = atoi(stringa);
        y++;
        sprintf(articolo_finale, "ART. %d.", y);
        pipe(p1p0);
        pid = fork();
        if (pid == 0)
        {
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
            execl("/usr/bin/grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
            return -1;
        }
        close(p1p0[1]);
        // close(0);
        // dup(p1p0[0]);
        // close(p1p0[0]);
        while (nread = read(p1p0[0], &buff, sizeof(buff)))
        {
            write(1, &buff, nread);
        }
    }
}