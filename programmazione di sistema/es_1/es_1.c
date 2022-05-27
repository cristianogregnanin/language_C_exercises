#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p0[2], pid;
    pipe(p1p0);

    pid = fork();

    if (pid == 0)
    {
        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        execl("/bin/cat", "cat", "file.txt", (char *)0);
        return -1;
    }

    pid = fork();
    if (pid == 0)
    {
        close(p1p0[1]);
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);
        execl("/bin/more", "more", (char *)0);
        return -1;
    }

    close(p1p0[1]);
    close(p1p0[0]);
    wait(&pid);
    wait(&pid);

    return 0;
}
