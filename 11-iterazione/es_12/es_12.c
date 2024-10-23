/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la
 * somma dei primi N numeri pari.
 *
 * @return Restituisce 0 se l'esecuzione del programma è andata a buon fine.
 */


#include <stdio.h>

int main(int argc, char *argv[])
{

	int n, i = 0, somma = 0;
	do
	{
		printf("Inserisci un numero positivo: \n");
		scanf("%d", &n);

	} while (n < 0);

	do
	{
		somma = somma + i;
		i = i + 2;
	} while (i <= n);
	printf("La somma vale: %d\n\n", somma);

	return 0;
}
