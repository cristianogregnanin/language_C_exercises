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

 // visto in classe
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0 && i < n - 1 && j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
