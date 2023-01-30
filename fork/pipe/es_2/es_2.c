#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM 3

int main(int argc, char *argv[])
{
    int pid, p0p1[2], p1p0[2];

    pipe(p0p1);
    pipe(p1p0);

    pid = fork();
    if (pid > 0)
    {
        int numeri[] = {1, 2, 3}, somma = 0;

        close(p0p1[0]);
        close(p1p0[1]);

        write(p0p1[1], numeri, sizeof(numeri));

        read(p1p0[0], (void *)&somma, sizeof(somma));
        printf("PADRE: somma %d\n", somma);
        exit(0);
    }
    else
    {

        int somma = 0, numeri[DIM];

        close(p0p1[1]);
        close(p1p0[0]);

        read(p0p1[0], numeri, sizeof(numeri));

        for (int i = 0; i < DIM; i++)
        {
            somma = somma + numeri[i];
        }
        printf("FIGLIO: somma %d\n", somma);
        write(p1p0[1], &somma, sizeof(somma));

        exit(0);
    }
}