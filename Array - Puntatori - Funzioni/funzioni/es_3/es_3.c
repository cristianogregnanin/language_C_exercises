#include <stdio.h>
#include <stdlib.h>

int ricerca_posizione(int n, char *argv[], int numero)
{
	int i;

	for (i = 1; i < n; i++)
		if (numero == atoi(argv[i]))
			return i;

	return -1;
}

int main(int argc, char *argv[])
{

	int numero;
	printf("Inserisci un numero da ricercare: ");
	scanf("%d", &numero);

	int posizione = ricerca_posizione(argc, argv, numero);

	if (posizione > 0)
		printf("numero %d trovato in posizione %d\n", numero, posizione);
	else
		printf("numero non trovato\n");

	return 0;
}
