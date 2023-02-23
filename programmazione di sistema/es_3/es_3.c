#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define DIM 1000

int main(int argc, char*argv[])
{
    
    if(argc != 2)
    {
        printf("Numero Parametri Errati");
    }

    int p1p0[2], pid,cnttot= 0;
    char stringa[DIM], cnt[DIM];
    pipe(p1p0);
    printf("inserire le stringhe\n");
    do
    {
        scanf("%s", stringa);
        pid = fork();
        if(pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep","grep","-c",stringa,argv[1],NULL);

            return -1;
        }
        read(p1p0[0],cnt,DIM);
        printf("Il file ha %d '%s' \n", atoi(cnt), stringa);
        cnttot += atoi(cnt);
    }while(strcmp(stringa,"fine") != 0);

    close(p1p0[1]);
    close(p1p0[0]);
    printf("\nnumero di parole trovate:  %d\n", cnttot);
    exit(1);

    return 0;
}