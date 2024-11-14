#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari
 * minori o uguali a N.
 * 
 * @param argc elementi digitati da riga di comando
 * @param argv numero di elementi digitati da riga di comando
 * 
 * @return la funzione restituisce 0
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
