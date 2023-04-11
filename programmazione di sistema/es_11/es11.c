#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 100

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("errore");
        exit(1);
    }

    int pid;
    int p1p2[2];
    char search_str[MAX], argomento_grep[MAX];
    while (1)
    {
        printf("Inserisci il numero dell'articolo che vuoi ricercare:\n");
        scanf("%s", search_str);
        if (strcmp(search_str, "esci") == 0)
        {
            exit(1);
        }
        pipe(p1p2);
        pid = fork();
        if (pid == 0)
        {
            close(p1p2[0]);
            write(p1p2[1], search_str, strlen(search_str) + 1);
            close(p1p2[1]);
            return 0;
        }
        pid = fork();
        if (pid == 0)
        {
            close(p1p2[1]);
            read(p1p2[0], search_str, strlen(search_str) + 1);
            sprintf(argomento_grep, "(?<=ART. %d.)(?s).*(?=ART. %d.)", atoi(search_str), atoi(search_str + 1));
            execl("/usr/bin/grep", "grep", "-z", "-o", "-P", argomento_grep, argv[1], (char *)0);
        }
    }
    close(p1p2[0]);
    wait(&pid);

    return 0;
}
