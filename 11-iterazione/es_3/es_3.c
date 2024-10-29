/**
*@brief Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari minori o uguali a N
*
*@param n Un numero intero positivo (il limite superiore).
* 
*@return 0 se l'esecuzione e' completata con successo
*/

#include <stdio.h>

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
