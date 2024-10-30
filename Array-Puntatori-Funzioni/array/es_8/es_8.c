/**
 * @brief Progettare un algoritmo che effettui la lettura da tastiera di una serie di valori numerici. Il
 * programma termina quando il dato immesso è pari a zero. Calcolare e stampare la media dei valori
 * inseriri. Inoltre, stampare la sequenza di valori in ordine inverso rispetto a quello di inserimento. Un
 * valore dovrà essere stampato soltanto se maggiore della media calcolata.
 * 
 * @param argc Numero di argomenti inseriti da riga di comando 
 * @param argv Array di stringhe contenente gli argomenti inseriti da riga di comando
 *
 * @return La funzione restituisce 0.
*/
#include <stdio.h>
#define DIM 100

int main(int argc, char *argv[])
{

	int somma = 0, i = 0, k, numero, numeri[DIM];
	double media;

	do
	{
		printf("inserisci il numero\n");
		scanf("%d", &numero);

		somma = somma + numero;

		numeri[i] = numero;
		i++;

	} while (numero != 0 && i < DIM);

	media = somma / i + 1;
	printf("la media è: %f\n\n", media);

	for (k = i - 1; k > 0; k--)
	{

		if (numeri[k] > media) 
		{
			printf("Il valore %d è maggiore della media %f\n", numeri[k], media);
		}	
	}

	return 0;
}
