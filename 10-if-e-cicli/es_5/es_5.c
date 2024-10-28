/**
 * @brief Progettare un algoritmo che effettui le seguenti operazioni:
 *	• continui a leggere da tastiera una serie di terne di valori interi A ,
 *	B e C finchè non vengono inseriti dei valori tali per cui A + B < C
 *	• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
 *	• prima di terminare, visualizzi il valore dei valori conteggiati
 *
 * @param argv Vettore di stringhe contenente gli argomenti passati attraverso la riga di comando
 * @param argc Numero di argomenti  passati attraverso la riga di comando
 *
 * @return La funzione restituisce 0
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b, c, diff, nulli = 0, pari = 0, dispari = 0;

	do
	{
		printf("\ninserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);
		printf("inserisci c\n");
		scanf("%d", &c);
		diff = a - b;

		if (diff == 0)
		{
			nulli++;
		}

		if (diff % 2 == 0)
		{
			pari++;
		}
		else
		{
			dispari++;
		}

	} while (a + b >= c);

	printf("\nnulli: %d\n", nulli);
	printf("pari: %d\n", pari);
	printf("dispari: %d\n\n", dispari);

	return 0;
}
