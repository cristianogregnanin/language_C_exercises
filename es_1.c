#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int j, i, n;

    if (argc != 2)
    {
        printf("argc = %d\n", argc);
        printf("il numero di argumenti (argc) deve risultare uguale a 2\n");
        exit(0);
    }

    n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("argv[1] deve essere maggiore di 0\n");
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != 0 && j < n - 1 && j != 0 && i < n - 1)
            {
                printf("  ");
            }
            else
            {
                printf(" *");
            }
        }
        printf("\n");
    }
    return 0;
}
