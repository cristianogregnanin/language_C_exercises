#include <stdio.h>
#define DIM 5

/**
 * @brief Chiedere in input 5 interi e inserirli in un array. Stampare a video l'array al contrario. Esempio: input 5 6 9 11 12 output 12 11 9 6 5
 *
 * @param argv Array di stringhe (array di caratteri) contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce 0 se il programma viene eseguito correttamente.
 */

int main(int argc, char *argv[])
{
	int i;
	int a[DIM];

	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci un numero: ");
		scanf("%d", &a[i]);
	}

	printf("Array al contrario:\n");
	for (i = DIM - 1; i >= 0; i--)
	{
		printf("il numero in posizione %d è: %d\n", i, a[i]);
	}

	return 0;
}
