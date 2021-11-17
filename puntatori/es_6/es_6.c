#include <stdio.h>
#include <string.h>

void ricerca(char string[], char carattere, int *k)
{

	int i;
	printf("ricerco occorrenze di %c in %s:\n\n", carattere, string);
	for (i = 0; i < strlen(string); i++)
		if (string[i] == carattere)
			++(*k);
}

int main(int argc, char **argv)
{

	int contatore = 0;
	ricerca(argv[1], argv[2][0], &contatore);

	printf("Il carattere %s compare %d volte in %s\n", argv[2], contatore, argv[1]);

	return 0;
}
