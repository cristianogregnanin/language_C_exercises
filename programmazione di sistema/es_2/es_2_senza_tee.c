#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* In questa soluzione si usano le system call per scrivere nel file wc.txt*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato");
        exit(1);
    }

    int fd, piped[2], pid, p2p0[2], nread;
    char buff[1000];
    pipe(piped);

    pid = fork();

    if (pid == 0)
    {
        close(1);
        dup(piped[1]);
        close(piped[1]);
        close(piped[0]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
    }

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(piped[0]);
        close(piped[0]);
        close(piped[1]);

        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);
        close(p2p0[0]);
        execl("/bin/wc", "wc", (char *)0);
    }

    close(piped[1]);
    close(piped[0]);
    close(p2p0[1]);

    fd = open("wc.txt", O_WRONLY | O_CREAT, 0777);
    while (nread = read(p2p0[0], buff, 1024 > 0))
    {
        write(fd, buff, nread);
    }
    close(p2p0[0]);
    close(fd);

    return 0;
}
