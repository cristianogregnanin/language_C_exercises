#include <stdio.h>
#include <string.h>

/**
 * @brief Unione di stringhe
 * 
 * scrivere in C un programma che concatena in un unica stringa le stringhe
 * chieste in input da riga di comando.
 * Esempio:
 * $./a.out ciao a tutti gli studenti
 * ciao a tutti gli studenti
 * 
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 * 
 * @return La funzione ritorna sempre 0.
*/
int main(int argc, char *argv[])
{

	int i, len = 0, k = 0, j;

	for (i = 1; i < argc; i++)
	{
		len = len + strlen(argv[i]);
	}

	len = len + argc - 2;
	printf("la stringa è lunga %d\n", len);

	char str[len];

	for (i = 1; i < argc; i++)
	{

		for (j = 0; j < strlen(argv[i]); j++)
		{
			str[k] = argv[i][j];
			k++;
		}
		str[k] = ' ';
		k++;
	}

	str[k - 1] = '\0';
	printf("%s\n", str);

	return 0;
}
