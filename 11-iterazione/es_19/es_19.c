/*
* @brief Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.

@param Devo passare alla funzione argc e argv

@return Il programma mi ritorna 0.
*/



#include <stdio.h>

int main(int argc, char *argv[])
{

	int a, b;
	double r;

	do
	{
		printf("inserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);

		if (a > b)
			r = (double)b / (double)a;
		else
			r = (double)a / (double)b;
		printf("\n\tIl risultato è: %f\n\n", r);
	} while (a != 0 && b != 0);

	return 0;
}