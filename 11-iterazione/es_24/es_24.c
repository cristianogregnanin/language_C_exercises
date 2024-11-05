/**
 * @file es_24.c
 * @brief Calcolo del numero di Bernoulli
 *
 * Funzione bernoulli che calcola la somma dei 
 * primi n numeri interi elevati alla potenza k. 
 * Funzione main dialogo con l'utente
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief Funzione principale per calcolare il numero di Bernoulli sommando i primi n numeri
 * interi elevati alla potenza k.
 *
 * Chiede all'utente di inserire i valori di n e k, e calcola
 * il numero di Bernoulli.
 *
 * @param argc Conteggio degli argomenti della linea di comando.
 * @param argv Array di stringhe contenente gli argomenti della linea di comando.
 *
 * @return La funzione ritorna sempre 0.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    int n;                // numero di n, i quali indici saranno moltiplicati per k
    double k;             // potenza
    double risultato = 0; // numero di Bernoulli, inizializzato a 0

    // Inserimento dell'utente
    printf("Inserisci il numero di n: ");
    scanf("%d", &n);

    printf("Inserisci la costante k: ");
    scanf("%lf", &k);

    // Calcolo del risultato
    for (int i = 1; i <= n; i++) {
        risultato += pow(i, k);
    }

    // Stampa del risultato
    printf("Il numero di Bernoulli e': %f\n", risultato);
    
    return 0;
}
