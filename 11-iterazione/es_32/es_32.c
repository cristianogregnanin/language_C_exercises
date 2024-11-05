/**
 * @brief Progettare un algoritmo che visualizzi tutti i divisori di un numero intero N.
 *
 * @param argc Numero di argomenti passati attraverso la riga di comando
 * @param argv argomenti passati attraverso la riga di comando
 *
 * @return La funzione restituisce 0
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

	int N;

	do
	{
		printf("Inserisci un numero intero positivo per trovarne i divisori: ");
		scanf("%d", &N);
	} while (N < 1);

	printf("\nI divisori di %d sono: ", N);

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
