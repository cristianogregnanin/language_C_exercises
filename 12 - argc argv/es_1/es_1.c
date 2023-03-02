#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Errore argomenti\n");
        exit(0);
    }

    int n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("argv[1] deve essere maggiore di 0\n");
        exit(0);
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (y != 0 && y < n - 1 && x != 0 && x < n - 1)
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