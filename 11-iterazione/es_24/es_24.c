
#include <stdio.h>
#include <math.h>

/**
 * @brief Dato un valore numerico costante k (non necessariamente intero), I'n-esimo numero di Bernoulli 
 * è dato dalla somma dei primi n numeri interi elevati alla potenza k; per esempio per n = 5: 1+2+3+4+5*
 * Progettare un algoritmo che determini, a partire dai valori della costante k e del numero n, il nu- mero di Bernoulli relativo.
 * @param n Numero di numeri da sommare.
 * @param k Potenza alla quale elevare i numeri.
 *
 * @return La somma dei primi n numeri interi elevati alla potenza k.
 */

int main(int argc, char *argv[])
{
 
    int n;            
    double k;       
    double risultato; 

   
    printf("Inserisci il numero di n: ");
    scanf("%d", &n);

    printf("Inserisci la costante k: ");
    scanf("%lf", &k);

    double somma = 0.0;
    for (int i = 1; i <= n; i++)
        somma += pow(i, k);

    
    risultato = somma;
    printf("Il numero di Bernoulli e': %f\n", risultato);

    return 0;
}
