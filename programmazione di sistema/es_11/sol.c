#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syscall.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Argomento sbagliato\n");
        return -1;
    }
    int pid, P1P2[2];
    char risposta[100], num[100], articolo_iniziale[100],articolo_finale[100], argomento_grep[100];

    while(1)
    {
        pipe(P1P2);
        pid = fork();
        if(pid == 0)
        {
            close(P1P2[0]);
            printf("Insersci il numero del articolo: \n");
            scanf("%s", risposta);
            if(strcmp(risposta, "Esci")==0)
            {
                return 0;
            }
            write(P1P2[1], risposta, sizeof(risposta));
            close(1);
        }

        pid = fork();
        if(pid == 0)
        {
            close(P1P2[1]);
            read(P1P2[0],num,sizeof(num));
            sprintf(argomento_grep, "'(?<=%s)(?s).*", num);
            sprintf(articolo_finale, "(?=%d)'", atoi(num)+1);
            strncat(argomento_grep, articolo_finale, sizeof(articolo_finale));
            execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
            return -1;
        }

        close(P1P2[0]);
        close(P1P2[1]);
    }
    return 0;
}