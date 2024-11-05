#include <stdio.h>
#include <math.h>

/**
 * @brief Calcola la somma dei primi n numeri interi elevati alla potenza k.
 *
 * Questa funzione calcola il numero di Bernoulli sommando i primi n numeri
 * interi elevati alla potenza k.
 *
 * @param argc Numero di numeri da sommare.
 * @param argv Potenza alla quale elevare i numeri.
 *
 * @return La somma dei primi n numeri interi elevati alla potenza k.
 */

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    int n;            // numero di n, i quali indici saranno moltiplicati per k
    double k;         // potenza
    double risultato; // numero di Bernoulli

    // Inserimento dell'utente
    printf("Inserisci il numero di n: ");
    scanf("%d", &n);

    printf("Inserisci la costante k: ");
    scanf("%lf", &k);

    double somma = 0.0;
    for (int i = 1; i <= n; i++)
        somma += pow(i, k);

    // Calcolo del risultato
    risultato = somma;
    printf("Il numero di Bernoulli e': %f\n", risultato);

    return 0;
}
