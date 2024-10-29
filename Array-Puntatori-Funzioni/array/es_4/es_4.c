#include <stdio.h>
#include <string.h>

/**
 * @brief Inverte una stringa di caratteri.
 * Questa funzione prende una stringa come argomento e la inverte sul posto.
 * 
 * @param s La stringa da invertire.
 * 
 * 
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
 * @param argc Numero di argomenti della riga di comando.
 * @param argv Array di stringhe che contiene gli argomenti della riga di comando.
 * 
 * @return int 0 se viene eseguito correttamente, -1 in caso di errore.
 * 
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
