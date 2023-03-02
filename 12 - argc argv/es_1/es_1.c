#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int N;

    do
    {
        printf("Inserisci N \n");
        scanf("%d", &N);
        if (N <= 0)
        {
            printf("Numero non valido. REINSERIRLO");
        }
    } while (N <= 0);
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if (r == 1 || r == N || c == 1 || c == N)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
    }
}