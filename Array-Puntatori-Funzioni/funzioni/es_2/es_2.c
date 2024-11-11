#include <stdio.h>
#include <stdlib.h>

/**
 * @brief funzione denominata somma che prenda in input un array di caratteri e il numero
 * dei caratteri presenti nell'array, calcola la somma dei numeri presenti nell'array
 *
 * @param n Numero di argomenti da riga di comando
 * @param argv stringa di caratteri
 * @return La funzione restituisce la somma
 */

int calcola_somma(int n, char *argv[])
{
	int i, somma = 0;

	for (i = 1; i < n; i++)
		somma = somma + atoi(argv[i]);

	return somma;
}

/**
 * @brief Si crei un programma che nel momento dell'esecuzione popoli l'array
 * argv[] con una serie di numeri. Esempio: $ ./a.out 1 5 9 6
 * Il programma deve calcolare la media dei numeri inseriti da riga di
 * comando.
 * Suggerimento: si usi una funzione per calcolare la somma dei numeri.
 *
 * @param argv Array di stringhe (array di caratteri) contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */

int main(int argc, char *argv[])
{

	int somma;
	double media;

	somma = calcola_somma(argc, argv);

	media = somma / (argc - 1);

	printf("la media è: %f\n", media);

	return 0;
}
