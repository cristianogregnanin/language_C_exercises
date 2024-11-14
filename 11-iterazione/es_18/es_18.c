#include <stdio.h>

/**
 * @brief Data una misura di tempo espressa in secondi S1, convertirla in ore H,
 * minuti M e secondi S.
 * Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
 * dal programma, 0h 27m 10s.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 *
 * @return La funzione ritorna sempre 0.
 */

int main(int argc, char *argv[])
{

	int s1, h, m, s;
	do
	{
		printf("Inserisci un numero positivo: ");
		scanf("%d", &s1);

	} while (s1 < 1);

	m = s1 / 60;
	s = s1 % 60;
	h = m / 60;
	m = m % 60;

	printf("%dh %dm %ds\n\n", h, m, s);

	return 0;
}
