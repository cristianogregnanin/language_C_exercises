#include <stdio.h>
#define DIM 10

/**
 * 
 * @brief Chiedere in input 10 interi e inserirli in un array.
 * Stampare a video prima tutti i numeri pari e 
 * in seguito tutti i numeri dispari
 * 
 * Esempio: 
 * input 5 6 9 11 12 13 14 10 8 21
 * output
 * 6 12 14 10 8
 * 5 9 11 13 21
 * 
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 * 
 * 
 * @return returna 0 se il programma è corretto
 */
int main(int argc, char *argv[])
{

	int i, resto;
	int a[DIM];

	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci un numero :");
		scanf("%d", &a[i]);
	}

	for (i = 0; i < DIM; i++)
	{
		resto = a[i] % 2;
		if (resto == 0)
			printf("%d è pari\n", a[i]);
	}

	for (i = 0; i < DIM; i++)
	{
		resto = a[i] % 2;
		if (resto != 0)
			printf("%d è dispari\n", a[i]);
	}
	return 0;
}
