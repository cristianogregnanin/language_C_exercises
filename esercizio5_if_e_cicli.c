#include <stdio.h>
///@brief progettazione di un algoritmo in C
///
///• continui a leggere da tastiera una serie di terne di valori interi A ,
///B e C finchè non vengono inseriti dei valori tali per cui A + B < C
///• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
///• prima di terminare, visualizzi il valore dei valori conteggiati
///
///@param i è un contatore, numero1, numero2 e numero3 sono i numeri della media, infine abbiamo la somma e la media
///
///
///@details il valore della media dei numeri inseriti
///@return il valore della media
///
int main(int argc, char *argv)
{
	int i = 0, somma = 0, numero1, numero2, numero3;
	double media;
	do
	{
		printf("inserisci numero1\n");
		scanf("%d", &numero1);
		printf("inserisci numero2\n");
		scanf("%d", &numero2);
	} while (numero2 < numero1);

	do
	{
		printf("inserisci un numero\n");
		scanf("%d", &numero3);

		if (numero3 >= numero1 && numero3 <= numero2)
		{
			somma = somma + numero3;
			i++;
		}

	} while (numero3 >= numero1 && numero3 <= numero2);
	media = (double)somma / (double)i;

	printf("\nla media è: %f\n\n", media);

	return 0;
}