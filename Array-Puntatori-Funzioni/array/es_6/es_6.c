#include <stdio.h>
#include <string.h>

/**
 * @brief Funzione per controllare se una parola è palindroma.
 *
 * Questa funzione verifica se una parola è palindroma confrontando i caratteri
 * dall'inizio e dalla fine della parola.
 *
 * @param parola La parola da verificare.
 * @return Restituisce 1 se la parola è palindroma, -1 altrimenti.
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
 *	$ ./a.out anna
 *	$ anna è una stringa palindroma
 *
 *	esempio:
 *	$ ./a.out ciao
 *	$ ciao non è una stringa palindroma
 * @param argc Numero di argomenti.
 * @param argv Array di argomenti passati al programma.
 * @return Restituisce 0 in caso di successo, -1 in caso di errore.
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