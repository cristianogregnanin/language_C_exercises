#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int piped[2], pid;
    pipe(piped);

    pid = fork();

    if (pid == 0)
    {
        close(1);
        dup(piped[1]);
        close(piped[1]);
        close(piped[0]);
        execl("/bin/cat", "cat", "file.txt", (char *)0);
    }

    pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(piped[0]);
        close(piped[1]);
        close(piped[0]);
        execl("/bin/more", "more", (char *)0);
    }
    
    wait(&pid);
    wait(&pid);
    close(piped[1]);
    close(piped[0]);

    return 0;
}
