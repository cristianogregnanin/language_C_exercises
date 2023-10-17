#include <stdio.h>
#include <string.h>

double somma(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a + b;
}

double divisione(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a / b;
}

double sottrazione(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a - b;
}

double moltiplicazione(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a * b;
}

int main(int argc, char *argv[])
{

    double a, b, risultato;
    int totale = 0;
    char operazione[4];

    do
    {
        printf("inserisci a: ");
        scanf("%lf", &a);
        printf("inserisci b: ");
        scanf("%lf", &b);
        printf("inserisci operazione: ");
        scanf("%s", operazione);

        if (strcmp(operazione, "+") == 0)
        {
            risultato = somma(a, b, &totale);
        }
        if (strcmp(operazione, "/") == 0)
        {
            risultato = divisione(a, b, &totale);
        }
        if (strcmp(operazione, "*") == 0)
        {
            risultato = moltiplicazione(a, b, &totale);
        }
        if (strcmp(operazione, "-") == 0)
        {
            risultato = sottrazione(a, b, &totale);
        }

        if (strcmp(operazione, "fine") != 0)
        {
            printf("Il risultato é: %.2f\n", risultato);
        }
    } while (strcmp(operazione, "fine") != 0);

    printf("Sono state eseguite %d operazioni.\n", totale);

    return 0;
}