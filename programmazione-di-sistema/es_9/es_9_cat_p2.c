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

    int p1p2[2], pid;
    char buff;

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(1);
        open(argv[2], O_WRONLY | O_CREAT, 0777);
        execl("/bin/cat", "cat", (char *)0);

        return -1;
    }
    close(p1p2[1]);
    close(p1p2[0]);

    return 0;
}
