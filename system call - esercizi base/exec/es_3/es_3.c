#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int pids[argc - 2];
    for (int i = 1; i < argc; i++)
    {
        pids[i - 1] = fork();
        if (pids[i - 1] == 0)
        {
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            printf("Exec ha terminato con errori");
            return -1;
        }
    }

    for (int i = 0; i < argc - 2; i++)
    {
        wait(&pids[i]);
    }
    return 0;
}
