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
 * @param argv Array di interi
 * @param argc Numero di numeri presenti nell'array
 *
 * @return La funzione restituisce sempre 0
 */
int main(int argc, char *argv[])
{
	int pari[4];
	pari[0] = 1;
	pari[1] = 1;
	pari[2] = 2;
	pari[3] = 2;

	int i, j, cont;
	int is_pari = 1;

	for (i = 0; i < 4; i++)
	{
		cont = 0;

		for (j = 0; j < 4; j++)
		{
			if (pari[i] == pari[j])
			{
				cont++;
			}
		}

		if (cont % 2 != 0)
		{
			is_pari = 0;
			break;
		}
	}

	if (is_pari)
	{
		printf("L'array è pari\n");
	}
	else
	{
		printf("L'array è dispari\n");
	}

	return 0;
}
