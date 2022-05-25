#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p0[2], pid, fd, nread;
    char buff;

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

    pid = fork();
    if (pid == 0)
    {
        close(p1p0[1]);

        fd = open(argv[2], O_WRONLY | O_CREAT, 0777);
        while (nread = read(p1p0[0], &buff, 1) > 0)
        {
            write(fd, &buff, nread);
        }
        close(p1p0[0]);
        close(fd);
        exit(0);
    }
    close(p1p0[1]);
    close(p1p0[0]);

    return 0;
}
