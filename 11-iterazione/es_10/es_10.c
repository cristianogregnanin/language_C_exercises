#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei primi N numeri interi. 
 *
 * Questo programma chiede all'utente di inserire un numero positivo,
 * quindi calcola la somma di tutti i numeri interi da 1 fino a quel numero.
 * 
 * @param argc Numero di argomenti della riga di comando.
 * @param argv Array di argomenti della riga di comando.
 * @return Restituisce 0 se il programma termina correttamente.
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
