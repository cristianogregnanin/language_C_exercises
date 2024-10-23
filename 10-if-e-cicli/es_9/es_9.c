/**
 * @brief Stampa il valore minimo e massimo di terne di numeri.
 *
 * Il codice chiede terne di numeri (A, B, C) all'utente 
 * finché tutti i valori sono non negativi. 
 * Se uno è negativo, il programma termina. Le terne 
 * vengono scartate se non rispettano A < B < C. 
 * Per quelle valide, il programma aggiorna i valori massimo e 
 * minimo, che vengono stampati prima di chiudere.
 *
 * @param argc Numero di argomenti inseriti da riga di comando 
 * @param argv Array di stringhe contenente gli argomenti inseriti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */

#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int a, b, c, min = INT_MAX, max = 0;

	do
	{
		printf("\ninserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);
		printf("inserisci c\n");
		scanf("%d", &c);

		if (a < b && b < c)
		{

			if (a < min)
				min = a;
			if (c > max)
				max = c;
		}
		else
		{
			printf("terna non valida\n");
		}

	} while (a >= 0 && b >= 0 && c >= 0);

	printf("\nmax: %d\n", max);
	printf("\nminimo: %d\n\n", min);

	return 0;
}
