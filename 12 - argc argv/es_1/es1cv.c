#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    if (argc != 2)
    {
        printf("valore non valido");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        for (int f = 0; f < n; f++)
        {
            if (i == 0 || i == n - 1 || f == 0 || f == n - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}