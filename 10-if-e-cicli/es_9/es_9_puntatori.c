/**
 * @brief Progettare un algoritmo che risolva il seguente problema. Si richieda 
 * all’utente di inserire una serie di terne di dati numerici (A, B, C). 
 * Il programma deve terminare quando uno dei valori inseriti è minore di
 * zero. Si scartino le terne nelle quali i valori non sono in ordine
 * strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
 * Su tutte le terne non scartate si calcoli il massimo e il minimo dei
 * valori inseriti. Si stampino a video tali valori massimi e minimi prima
 * di terminare il programma.
 *
 * @param argc Numero di argomenti inseriti da riga di comando 
 * @param argv Array di stringhe contenente gli argomenti inseriti da riga di comando
 *
 * @return La funzione restituisce 0.
 */
#include <stdio.h>
#include <limits.h>

void calcola_min_max(int a, int b, int c, int *min, int *max)
{
	if (a < b && b < c)
	{

		if (a < *min)
			*min = a;
		if (c > *max)
			*max = c;
	}
	else
	{
		printf("terna non valida\n");
	}
}

int main(int argc, char *argv[])
{
	int a, b, c;
	int min = INT_MAX, max = 0;

	do
	{
		printf("\ninserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);
		printf("inserisci c\n");
		scanf("%d", &c);

		calcola_min_max(a, b, c, &min, &max);

	} while (a >= 0 && b >= 0 && c >= 0);

	printf("\nmax: %d\n", max);
	printf("\nminimo: %d\n\n", min);

	return 0;
}
