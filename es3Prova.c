#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero parametri errato\n");
        exit(1);
    }

    int pid = fork();
    pipe(p1p0);
    char stringa[30];
    char buff[40];
    int nread;

    while (1){
        printf("Parola da cercare? ");
        scanf("%s", stringa);

        if (strcmp(stringa) == "fine")
        {
            close(p1p0[1]);
            close(p1p0[0]);
            
        }
        else
        {
            nread= read(p1p0[0], atoi(buff), sizeof(buff) );
        }
        exit(1);
    }

    if(pid == 0){
        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        exec("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0);

        return -1;
    }

    return 0;
}