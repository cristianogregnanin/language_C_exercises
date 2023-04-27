#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Argomenti errati");
        return -1;
    }

    int pid, p1p2[2];
    char stringa[5], argomento_grep[50], articolo_iniziale[10], articolo_finale[15];
    int nread;
    char buff[50];

    pipe(p1p2);
    pid = fork();

    while(1)
    {
        printf("Inserisci il numero dell’articolo che vuoi ricercare: \n");
        scanf("%s", stringa);

        if (strcmp(stringa, "esci") == 0)
        {
            return 0;
        }

        sprintf(articolo_iniziale, "ART. %s.", stringa);
        sprintf(articolo_finale, "ART. %d.", atoi(stringa) + 1);
        sprintf(argomento_grep, "(?<=%s)(?s).*(?=%s)", articolo_iniziale, articolo_finale);

        if (pid == 0)
       {
           close(p1p2[0]);
           close(1);
           dup(p1p2[1]);
           close(p1p2[1]);
           execl("/usr/bin/grep", "-z", "-o", "-P", argomento_grep, argv[1], NULL);
           return -1;
       }
    }

    while (nread = read(p1p2[0], buff, strlen(buff)))
    {
       write(1, buff, nread);
    }

    close(p1p2[1]);
    close(p1p2[0]);
    
    return 0;
}
