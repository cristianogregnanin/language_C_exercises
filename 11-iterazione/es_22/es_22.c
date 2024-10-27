#include <stdio.h>
/**
 * 
 * @brief Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
 *	danno per somma il numero stesso. Non considerare la proprietà commutativa. 
 * 
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 * 
 * 
 * @return returna 0 se il programma è corretto
 */

int main(int argc, char *argv[])
{
	int n, j = 1, i;

	do
	{
		printf("Inserisci un numero > 0 : ");
		scanf("%d", &n);
	} while (n < 0);

	i = n - 1;

	do
	{
		printf("%d+%d=%d\n", j, i, n);
		j++;
		i--;
	} while (j <= n);

	return 0;
}
