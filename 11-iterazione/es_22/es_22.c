#include <stdio.h>
/**
 * 
 * @brief Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
 * 	danno per somma il numero stesso. Non considerare la proprietà commutativa.  
 * 
 * @param n che è il numero da inserire
 * @param j che è inizializzato a 1 e serve per la somma dei numeri 
 * @param i viene inizializzato togliendo a 1 il numero inserito
 * 
 * @brief il programma chiede l'inserimento del numero all'utente e poi successivamente 
 * calcola la somma dei numeri che possono dare il numeri inserito
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
