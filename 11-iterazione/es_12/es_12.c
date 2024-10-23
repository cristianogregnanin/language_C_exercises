#include <stdio.h>
/**
* @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei primi N numeri pari.
* 
* @param argc, lunghezza del array argv
* 
* @param argv, array dove vengono inseriti dei dati da terminale
*/
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
