#include <stdio.h>

/**
  * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei primi N numeri pari
  *
  * @param argv, array con all'interno i valori che vengono passati da terminale
  *
  * @param argc, Lunghezza dell'array argv
  *
  * @return ritorna 0 se il programma funziona
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
