#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato");
        exit(1);
    }

    int fd, p1p0[2], pid, p2p0[2];
    pipe(p1p0);

    pid = fork();

    if (pid == 0)
    {
        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(p1p0[1]);
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);
        execl("/bin/wc", "wc", (char *)0);
        return -1;
    }

    close(p1p0[1]);
    close(p1p0[0]);
    close(p2p0[1]);

    close(0);
    dup(p2p0[0]);
    close(p2p0[0]);

    fd = open("wc.txt", O_WRONLY | O_CREAT, 0777);
    close(1);
    dup(fd);
    close(fd);

    execl("/usr/bin/tee", "tee", (char *)0);

    return -1;
}
