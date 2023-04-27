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
    int pid,P1P0[2], nread;
    char risposta[100], articolo_iniziale[100],articolo_finale[100], argomento_grep[100], buff;

    while(1)
    {
        pipe(P1P0);
        printf("Insersci il numero del articolo: \n");
        scanf("%s", risposta);
        if(strcmp(risposta, "Esci")==0)
        {
            return 0;
        }

        pid = fork();
        if(pid == 0)
        {
            close(P1P0[0]);         
            close(1);
            dup(P1P0[1]);   
            sprintf(argomento_grep, "'(?<=%s)(?s).*", risposta);
            sprintf(articolo_finale, "(?=%d)'", atoi(risposta)+1);
            strncat(argomento_grep, articolo_finale, sizeof(articolo_finale));
            execl("/usr/bin/grep", "grep", "-z", "-o", argomento_grep, argv[1], NULL);
            return -1;
        }
        close(P1P0[1]);
        while(read(P1P0[0], &buff, sizeof(buff))>0){
            write(1,&buff,sizeof(buff));
            printf("%c", buff);
        }
        close(P1P0[0]);
    }
    return 0;
}