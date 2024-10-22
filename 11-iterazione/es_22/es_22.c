/**
 * @brief Calcola e visualizza tutte le coppie di numeri minori di N che danno per somma N.
 * 
 * Il programma chiede un numero intero positivo N e visualizza tutte le coppie di numeri j e i
 * (dove j < N e i < N) tali che la loro somma è uguale a N, senza considerare la proprietà commutativa.
 * 
 * @return 0 in caso di successo.
 */
#include <stdio.h>

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
