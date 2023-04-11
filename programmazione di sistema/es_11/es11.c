#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pid,p1p2[2],tmp;
    char stringa[50];
    while(1){
        pipe(p1p2);
        pid=fork();
        if(pid==0)
        {
            
            printf("Inserisci il numero dell'articolo");
            scanf("%d",&p1p2[1]);
            close(p1p2[0]);
            exit(1);
        }
        pid=fork();
        if(pid==0)
        {
            tmp=p1p2[0];
            tmp++;
            close(p1p2[1]);
            sprintf(stringa,"(?<=%d)(?s).*(?=%d)",p1p2[1],tmp);
            close(p1p2[1]);
            execl("/usr/bin/grep", "-z", "-o", stringa, argv[1], (char *)0);
            return -1;
        }
        sprintf(stringa,"%d",p1p2[0]);
        if(strcmp(stringa,"esci")==0)
            {
                exit(1);
            }
        close(p1p2[1]);
        close(p1p2[0]);
    }
}