#include <stdio.h>
/**
* @brief Scrivere un programma in linguaggio C che dato un array di interi mostri
*	 in output se l'array è pari.
*	 Esempio:
*	 [1,1,2,1,2,1,2,2] => è pari
*	 [1,1,2] => dispari
*	 [3,3,4,5] => dispari
*	 [1,2,1,2] => pari
*
* @param a[] Array di interi
* @param n Numero di numeri presenti nell'array
* 
* @return La funzione restituisce 0 se l'array è pari
* @return La funzione restituisce 1 se l'array è dispari
*/
int isPari(int a[], int n)
{
	int i, j, cont;

	for (i = 0; i < n; i++)
	{
		cont = 0;

		for (j = 0; j < n; j++)
		{
			if (a[i] == a[j])
				cont++;
		}

		if ((cont % 2) != 0)
			return -1;
	}

	return 0;
}
/**
* @brief Scrivere un programma in linguaggio C che dato un array di interi mostri
*	 in output se l'array è pari.
*	 Esempio:
*	 [1,1,2,1,2,1,2,2] => è pari
*	 [1,1,2] => dispari
*	 [3,3,4,5] => dispari
*	 [1,2,1,2] => pari
*
* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* @param argc Numero di argomenti passati attraverso la riga di comando
* 
* @return La funzione restituisce 0
*/
int main(int argc, char *argv[])
{

	int pari[4];
	pari[0] = 1;
	pari[1] = 1;
	pari[2] = 2;
	pari[3] = 3;

	if (isPari(pari, 4) == 0)
		printf("L'array è pari\n");
	else
		printf("L'array è dispari\n");

	return 0;
}
