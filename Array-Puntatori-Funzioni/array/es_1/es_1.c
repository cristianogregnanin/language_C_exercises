/**
 * @file main.c
 * @brief Popolare un array di interi di dimensione 4, stamparne a video il contenuto.
 * 
 * @param argc Numero di argomenti da riga di comando
 * @param argv Array di stringhe contenente gli argomenti da riga di comando
 * 
 * @return la funzione restituisce sempre 0
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

	int i, n = 4;
	int a[n];

	for (i = 0; i < n; i++)
	{
		printf("Inserisci un numero :\n");
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("il numero in posizione %d è: %d\n", i, a[i]);
	}

	return 0;
}
