#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])

{

    int n, numero, i = 0;

    double somma = 0;

    do
    {

        printf("Inserisci N maggiore di zero: ");

        scanf("%d", &n);

    } while (n <= 0);

    do
    {

        printf("Inserisci un numero: \n");

        scanf("%d", &numero);

        i++;

        if (numero >= 0)
        {

            somma = somma + sqrt(numero);
        }
        else
        {

            printf("Hai inserito un numero negativo\n");
        }

    } while (i < n && numero >= 0);

    printf("La somma è: %f", somma);

    return 0;
}
