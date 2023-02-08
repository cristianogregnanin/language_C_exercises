#include <stdio.h>
#include <stdlib.h>

int massimo(int argc, char *argv[])
{
    int max = atoi(argv[1]), numero;
    for (int i = 2; i < argc; i++)
    {
        numero = atoi(argv[i]);
        if (numero > max)
            max = numero;
    }
    return max;
}

void pari(int argc, char *argv[], int pari[], int *dim_numeri_pari)
{
    int numero, k = 0;
    for (int i = 1; i < argc; i++)
    {
        numero = atoi(argv[i]);
        if ((numero % 2) == 0)
        {
            pari[k] = numero;
            k++;
            (*dim_numeri_pari)++;
        }
    }
}

int main(int argc, char *argv[])
{
    int max = massimo(argc, argv);
    printf("Il numero più grande è: %d\n\n", max);

    int numeri_pari[argc], dim_numeri_pari = 0;
    pari(argc, argv, numeri_pari, &dim_numeri_pari);

    printf("I numeri pari sono: \n");
    for (int i = 0; i < dim_numeri_pari; i++)
    {
        printf("%d\n", numeri_pari[i]);
    }
}