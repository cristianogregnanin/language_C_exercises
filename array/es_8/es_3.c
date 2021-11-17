#include <stdio.h>
#define DIM 100

int main()
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
			printf("Il valore %d è maggiore della media %f\n", numeri[k], media);
	}

	return 0;
}
