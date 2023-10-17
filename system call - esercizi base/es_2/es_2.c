#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])

{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    char alfabeto[] = "abcdefghijklmnopqrstuvz";
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    write(fd, alfabeto, strlen(alfabeto));
    write(fd, "\n", strlen("\n"));
    close(fd);

    return 0;
}