#include <stdio.h>
#include <stdlib.h>
/**
* @brief Funzione che individua il numero max presente nell'array.
*
* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* @param argc Numero di argomenti passati attraverso la riga di comando
* 
* @return La funzione restituisce int max
*/
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

/**
* @brief Funzione void che popola l'array di numeri pari
*
* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* @param argc Numero di argomenti passati attraverso la riga di comando
* @param pari Array di interi che andra' riempito con i numeri pari trovati ogni volta che viene inserito
* @return La funzione ritorna la quantita' di numeri pari
*/

int pari(int argc, char *argv[], int pari[])
{
    int numero, k = 0;
    for (int i = 1; i < argc; i++)
    {
        numero = atoi(argv[i]);
        if ((numero % 2) == 0)
        {
            pari[k] = numero;
            k++;
        }
    }
    return k;
}

/**
* @brief Si scriva un programma in linguaggio C che legga in input da
* argv 10 numeri interi non negativi.
* Scrivere quindi le seguenti funzioni che saranno richiamate nel
* main:
* 1) massimo: torna in output la posizione del numero piu' grande
* 2) pari: torna in output un array contenente i numeri pari
*
* Esempio di utilizzo:
* $ ./compito 15 20 33 40 55 60 75 80 95 100
* Il numero più grande e': 100
*
* I numeri pari sono: 
* 20
* 40
* 60
* 80
* 100
*
* Suggerimento: per convertire una stringa in numero intero usare
* la funzione atoi:
*
* /include <stdlib.h>
* int numero = atoi("10");
*
* @param argc argc numero di argomenti passati da riga di comando
* @param argv argv argomenti passati da riga di comando
*
*/

int main(int argc, char *argv[])
{
    int max = massimo(argc, argv);
    printf("Il numero più grande e': %d\n\n", max);

    int numeri_pari[argc];
    int dim_numeri_pari = pari(argc, argv, numeri_pari);

    printf("I numeri pari sono: \n");
    for (int i = 0; i < dim_numeri_pari; i++)
    {
        printf("%d\n", numeri_pari[i]);
    }
}

