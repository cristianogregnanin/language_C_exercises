#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    execl("/usr/bin/cp", "cp", argv[1], argv[2], NULL);

    printf("Exec ha terminato con errori");
    return -1;
}
