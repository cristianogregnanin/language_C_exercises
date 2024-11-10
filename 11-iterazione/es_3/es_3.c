#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari minori o uguali a N.
 * Nella funzione viene dichiarato un numero N, che successivamente viene chiesto in input all'utente. 
 * Nel caso in cui l'utente inserisca un numero minore di 0, viene fatto reinserire. 
 * Viene stampato il messaggio che introduce l'elenco dei numeri dispari. 
 * La variabile i parte da 1 e, in ogni iterazione del ciclo, viene stampata e incrementata 
 * di 2 per passare al numero dispari successivo. Il ciclo continua finché i non supera n.
 * @param argc Numero argomenti riga di comando
 * @param argv Array di stringhe argomenti riga di comando
 * @return La funzione restituisce sempre 0
 */

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
