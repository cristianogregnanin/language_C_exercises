/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei
 * primi N numeri dispari.
 *
 * @param argv Array di stringhe (vettori di caratteri) contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{

	int n, i, somma;
	do
	{
		printf("Inserisci un numero positivo: \n");
		scanf("%d", &n);

	} while (n < 0);

	somma = 0;
	i = 1;
	do
	{
		somma = somma + i;
		i = i + 2;
	} while (i < n);
	printf("La somma vale: %d\n\n", somma);

	return 0;
}
