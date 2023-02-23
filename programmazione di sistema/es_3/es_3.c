#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc; char*argv[])
{
    int pid;
    char word[80], tot[900];
    int p1p0[2], only[900];
    pipe(p1p0);
    while(1)
    {
        printf("Inserisci una stringa:");
        scanf("%s", word);
        if(strcmp(word, "fine") == 0)
        {
            close(p1p0[0]);
            close(p1p0[1]);
            printf("Program terminated");
            exit(0);
        }
        pid = fork();
        if(pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep", "grep", "-c", word,argv[1], NULL);
            return -1;
        }
        read(p1p0[0], only, sizeof(only));
        printf("Il file ha %d di %s", atoi(only), word);
        tot = tot + atoi(only);
    }
    return o;
}
