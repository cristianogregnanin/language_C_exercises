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
    int c = 0;

    if (n <= 0)
    {
        printf("argv[1] deve essere maggiore di 0\n");
        exit(0);
    }
    if (n == 2)
    {
        for(int i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
        for(int i = 0; i < n; i++)
        {
            printf("*");
        }
    }
    else
    {
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
    do
    {
        printf("\n");
        printf("*");
        for (int i = 0; i < n - 2; i++)
        {
            printf(" ");
        }
        printf("*");
        c++;
    } while (c < n - 2);
        printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
    }
    return 0;
}