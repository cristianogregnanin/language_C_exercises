#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define DIM_BUFFER 1024

/* In questa soluzione si usano le system call per scrivere nel file wc.txt*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int fd, p1p0[2], pid, p2p0[2], nread;
    char buff[DIM_BUFFER];
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

    fd = open("wc.txt", O_WRONLY | O_CREAT, 0777);
    while (nread = read(p2p0[0], buff, sizeof(buff)) > 0)
    {
        write(fd, buff, nread);
    }
    close(p2p0[0]);
    close(fd);

    return 0;
}
