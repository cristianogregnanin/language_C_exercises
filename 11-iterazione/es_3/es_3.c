#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari
 * minori o uguali a N.
 *
 * @param argv, array con all'interno i valori che vengono passati da terminale
 * @param argc, Lunghezza dell'array argv
 *
 * @return 0 se il programma termina correttamente.
*/

int main(int argc, char *argv[])
{

	int n, i = 1;

	do
	{

		printf("Immetti un numero: ");
		scanf("%d", &n);
	} while (n < 0);

	printf("I numeri dispari compresi fra %d e %d sono:\n\n", i, n);
	do
	{
		printf("%d\n", i);
		i = i + 2;

	} while (i <= n);

	return 0;
}
