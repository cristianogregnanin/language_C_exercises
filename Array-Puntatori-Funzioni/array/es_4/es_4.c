#include <stdio.h>
#include <string.h>

/**
 * @brief Funzione che inverte una stringa
 * 
 * @param s stringa da invertire
*/
void inverti(char s[])
{

	char tmp;
	int i, j = strlen(s) - 1;

	for (i = 0; i < j; i++)
	{

		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		j--;
	}
}

/**
 * @brief Si legga da riga di comando una stringa e la si mostri in output invertita.
 * 
 * @param argc numero di argomenti passati da riga di comando
 * @param argv argomenti passati da riga di comando
 * 
 * @return -1 se il numero di argomenti passati da riga di comando è errato.
 * 			0 in tutti gli altri casi
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Numero argomenti errato\n");
		return -1;
	}

	inverti(argv[1]);

	printf("stringa invertita: %s\n", argv[1]);

	return 0;
}
