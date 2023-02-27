#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("error 101");
        return 0;
    }

    int pid;

    for (int i = 1; i < argc ; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            return -1;
        }
        wait(&pid);
    }
    return 0;
}