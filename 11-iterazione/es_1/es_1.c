#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare il numero successivo.
 * 
 * @param argc numero di argomenti passati da riga di comando
 * @param argv argomenti passati da riga di comando
 * 
 * @return il programma ritorna sempre 0
*/
int main(int argc, char *argv[])
{

	int n, s; // dichiarazione variabili di tipo intero

	do
	{									   // ripeti
		printf("inserisci un numero: \n"); // Scrivi inserisci un numero
		scanf("%d", &n);				   // leggi n
	} while (n <= 0);					   // finche n<=0

	s = n + 1;
	printf("il successivo vale: %d\n\n", s); // scrivi s

	return 0; // la funzione main deve ritornare un valore int
}
