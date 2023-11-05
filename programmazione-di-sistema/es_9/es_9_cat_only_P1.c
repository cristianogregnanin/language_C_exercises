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

    /*
    Questa soluzione sebbene non aderente al testo dell'esercizio usa un solo
    processo per copiare un file da una posizione all'altra.
    A scopo didattico è anche possibile usare nessun processo oltre P0
    */
    if (fork() == 0)
    {
        close(0);
        open(argv[1], O_RDONLY);

        close(1);
        open(argv[2], O_WRONLY | O_CREAT, 0777);

        execl("/bin/cat", "cat", (char *)0);
        return -1;
    }

    return 0;
}
