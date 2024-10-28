/**
 * @brief Chiedere in input 5 interi e inserirli in un array. Stampare a video l'array al contrario. Esempio: input 5 6 9 11 12 output 12 11 9 6 5
 *
 * La funzione richiede all'utente di inserire 5 numeri interi, con cui andrà a popolare un vettore.
 * Successivamente, l’algoritmo stampa i valori del vettore, dall'ultimo al primo.
 *
 * @param argv Vettore di stringhe (vettori di caratteri) contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */

#include <stdio.h>
#define DIM 4

int main(int argc, char *argv[])
{

	int i;
	int a[DIM];

	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci un numero :");
		scanf("%d", &a[i]);
	}

	for (i = DIM - 1; i >= 0; i--)
	{
		printf("il numero in posizione %d è: %d\n", i, a[i]);
	}

	return 0;
}
