#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    execl("/usr/bin/cat", "cat", argv[1], NULL);

    printf("Exec ha terminato con errori");
    return -1;
}
