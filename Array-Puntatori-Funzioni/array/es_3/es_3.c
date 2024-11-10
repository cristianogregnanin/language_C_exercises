#include <stdio.h>
#define DIM 10

/**
 * @brief Chiedere in input 10 interi e inserirli in un array.
 * 
 * Stampare a video prima tutti i numeri pari e 
 * in seguito tutti i numeri dispari
 *
 * Esempio di input e output:
 * 
 * Input: 5 6 9 11 12 13 14 10 8 21
 * 
 * Output:
 * 6 12 14 10 8
 * 
 * 5 9 11 13 21
 *
 * @param argc Numero degli argomenti passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da riga di comando.
 *
 * @return Ritorna 0 se il programma è eseguito correttamente.
 */

int main(int argc, char *argv[])
{
	int i;
	int a[DIM];

	// Inserimento dei numeri nell'array
	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci un numero: ");
		scanf("%d", &a[i]);
	}

	// Stampa dei numeri pari
	printf("Numeri pari:\n");
	for (i = 0; i < DIM; i++)
	{
		if (a[i] % 2 == 0)
			printf("%d ", a[i]);
	}
	printf("\n");

	// Stampa dei numeri dispari
	printf("Numeri dispari:\n");
	for (i = 0; i < DIM; i++)
	{
		if (a[i] % 2 != 0)
			printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
