#include <stdio.h>
#define DIM 5

/**
 * @brief Chiede in input 5 numeri interi, li inserisce in un array e li stampa in ordine inverso.
 *
 * La funzione richiede all'utente di inserire 5 numeri interi, che vengono memorizzati in un array.
 * 
 * Successivamente, i valori dell'array sono stampati dall'ultimo al primo.
 *
 * @return La funzione restituisce sempre 0.
 */

int main()
{
	int i;
	int a[DIM];

	// Inserimento dei numeri nell'array
	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci un numero: ");
		scanf("%d", &a[i]);
	}

	// Stampa dell'array in ordine inverso
	printf("Array al contrario:\n");
	for (i = DIM - 1; i >= 0; i--)
	{
		printf("il numero in posizione %d è: %d\n", i, a[i]);
	}

	return 0;
}
