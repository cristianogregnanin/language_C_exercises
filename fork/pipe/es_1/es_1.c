#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid, p1p0[2];
    char buffer[80];

    pipe(p1p0);

    pid = fork();

    if (pid == 0)
    {

        close(p1p0[0]);
        char stringa[] = "Hello, world!\n";
        write(p1p0[1], stringa, sizeof(stringa));

        exit(0);
    }

    close(p1p0[1]);

    read(p1p0[0], buffer, sizeof(buffer));

    printf("PADRE: ricevuta stringa dal processo figlio: %s\n", buffer);
    return 0;
}