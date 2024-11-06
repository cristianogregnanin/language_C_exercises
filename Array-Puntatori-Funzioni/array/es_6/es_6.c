#include <stdio.h>
#include <string.h>

/** 
 * @brief funzione
 * denominata palindroma che prenda in input una stringa e restituisca
 * 1 se la stringa é palindroma altrimenti -1
 *  
 * @param parola array di caratteri
 * 
 * @return La funzione restituisce 1 se la stringa è palindroma
 * @return La funzione restituisce -1 se la stringa non è palindroma
 */

int palindroma(char parola[])
{
	int i, k = strlen(parola) - 1;

	for (i = 0; i <= k; i++)
	{
		if (parola[i] != parola[k])
			return -1;
		k--;
	}

	return 1;
}

/**
 * @brief Si scriva un programma in linguaggio C che implementi una funzione
 * denominata palindroma che prenda in input una stringa e restituisca
 * 1 se la stringa è palindroma altrimenti -1
 * esempio:
 * $ ./a.out anna
 * $ anna è una stringa palindroma
 * esempio:
 * $ ./a.out ciao
 * $ ciao non è una stringa palindroma
 *
 * @param argv Array di char contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Numero argomenti sbagliato\n");
		return -1;
	}

	if (palindroma(argv[1]) > 0)
		printf("%s è una parola palindroma\n", argv[1]);
	else
		printf("%s non è una parola palindroma\n", argv[1]);

	return 0;
}
