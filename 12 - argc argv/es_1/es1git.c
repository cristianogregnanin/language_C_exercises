#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Valore inserito non valido");
        exit(0);
    }
    int n = atoi(argv[1]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n - 1; k++)
        {
            if (i == 0 || k == 0 || i == n - 1 || k == n - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}