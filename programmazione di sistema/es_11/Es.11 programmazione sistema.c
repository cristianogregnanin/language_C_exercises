#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("numero di argomenti errati\n");
        return -1;
    }
    char s[4],argomento_grep[100], articolo_iniziale[10], articolo_finale[10], articolo[4];
    pid_t pid;
    int p1p2[2], conta;
    pipe(p1p2);
    pid=fork();
    while (1)
    {
        if (pid==0)
        {
            close(p1p2[0]);
            printf("Inserisci il numero dell’articolo che vuoi ricercare:\n");
            scanf("%s",s);
            if (strcmp(s,"esci")==0)
            {
                close(p1p2[1]);
                close(p1p2[0]);
                exit(0);
            }
            else
            {
               close(p1p2[1]);
               write(p1p2[1], s, strlen(s));
            }
        }     
        pid=fork();
        if (pid==0)
        {
            close(p1p0[1]);
            read(p1p0[0], articolo, strlen(articolo));
            close(p1p0[0]);
            sprintf(articolo_iniziale, "ART. %s.", articolo);
            conta = atoi(articolo) + 1;
            sprintf(articolo_finale, "ART. %d.", conta);
            sprintf(argomento_grep, "-P '(?<=%s)(?s).*(?=%s)'", articolo_iniziale, articolo_finale);
            execl("/usr/bin/grep","grep","-z","-o",argomento_grep,argv[1],(char *)0);
            return -1;
        }
    }
    wait(&pid);
    wait(&pid);
    close(p1p2[0]);
    close(p1p2[1]);
    return 0;        
}
