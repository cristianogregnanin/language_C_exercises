#include <stdio.h>
#include <math.h>

/**
 * @brief Calcola il numero di Bernoulli sommando i primi n numeri interi
 *        elevati alla potenza k
 *
 * @param n Numero di numeri da sommare
 * @param k Potenza
 *
 * @return La somma dei primi n numeri interi elevati alla potenza k
 */

double bernoulli(int n, double k)
{ // Funzione per calcolare l'n-esimo numero di Bernoulli
    double somma = 0.0;
    for (int i = 1; i <= n; i++)
        somma += pow(i, k);

    return somma;
}

/**
 * @brief Funzione principale che, chiedendo all'utente n e k,
 * calcola il numero di Bernoulli
 * 
 * @param argc Conteggio argomenti
 * @param argv Indice dell'argomento
 * 
 * @return la funzione ritorna sempre 0
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

    // Risultato
    risultato = bernoulli(n, k);
    printf("Il numero di Bernoulli e': %f", risultato);

    return 0;
}
