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

    int p1p2[2], pid, fd, nread;
    char buff;

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);

        fd = open(argv[1], O_RDONLY);

        while (nread = read(fd, &buff, sizeof(buff)) > 0)
        {
            write(p1p2[1], &buff, nread);
        }
        close(p1p2[1]);
        close(fd);
        exit(0);
    }

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[1]);

        fd = open(argv[2], O_WRONLY | O_CREAT, 0777);
        while (nread = read(p1p2[0], &buff, sizeof(buff)) > 0)
        {
            write(fd, &buff, nread);
        }
        close(p1p2[0]);
        close(fd);
        exit(0);
    }
    close(p1p2[1]);
    close(p1p2[0]);

    return 0;
}
