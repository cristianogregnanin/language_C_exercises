#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    int fd, piped[2], pid, p2p0[2];
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

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(piped[0]);
        close(piped[1]);
        close(piped[0]);

        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);
        close(p2p0[0]);
        execl("/bin/wc", "wc", (char *)0);
    }

    close(piped[1]);
    close(piped[0]);
    close(p2p0[1]);

    close(0);
    dup(p2p0[0]);
    close(p2p0[0]);

    fd = open("wc.txt", O_WRONLY | O_CREAT, 0777);
    close(1);
    dup(fd);
    close(fd);

    execl("/usr/bin/tee","tee",(char *)0);

    return 0;
}
