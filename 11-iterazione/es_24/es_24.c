#include <stdio.h>
#include <math.h>

/**
 * @brief Dato un valore numerico costante k (non necessariamente intero), I'n-esimo numero di Bernoulli
 * è dato dalla somma dei primi n numeri interi elevati alla potenza k; per esempio per n = 5: 1+2+3+4+5*\n
 * Progettare un algoritmo che determini, a partire dai valori della costante k e del numero n, il numero di Bernoulli relativo.
 *
 * @param argc Numero di argomenti da riga di comando.
 * @param argv Array di stringhe contenente gli argomenti da riga di comando.
 *
 * @return la funzione ritorna 0.
 */

int main(int argc, char *argv[])
{

    int n;
    double k, somma = 0.0;

    printf("Inserisci il numero di n: ");
    scanf("%d", &n);

    printf("Inserisci la costante k: ");
    scanf("%lf", &k);

    for (int i = 1; i <= n; i++)
    {
        somma = somma + pow(i, k);
    }

    printf("Il numero di Bernoulli e': %f\n", somma);

    return 0;
}
