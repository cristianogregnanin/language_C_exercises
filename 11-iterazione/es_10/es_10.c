#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei
 * primi N numeri interi. 
 * 
 * @param argc Numero di argomenti da riga di comando (non utilizzato).
 * @param argv Array di stringhe contenente gli argomenti da riga di comando (non utilizzato).
 *
 * @return Restituisce 0 se l'esecuzione del programma è andata a buon fine.
 */

int main(int argc, char *argv[])
{

	int n, i, somma;
	do
	{
		printf("Inserisci un numero positivo: \n");
		scanf("%d", &n);

	} while (n < 0);

	somma = 0;
	i = n;
	do
	{
		somma = somma + i;
		i = i - 1;
	} while (i > 0);
	printf("La somma vale: %d\n\n", somma);

	return 0;
}
