#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    
    if (argc != 2) 
    {
        printf("Errore argomenti \n");
        exit (0);
    }
    
    int N=atoi(argv[1]);
    if (N<0) 
    {
        printf ("Devi inserire un numero maggiore di 0\n");
        exit (0);
    }
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
    return 0;
}