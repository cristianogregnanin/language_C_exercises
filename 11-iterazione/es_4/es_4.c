#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine
 *        crescente i numeri pari minori o uguali a N.
 * 
 * @param argc Numero degli argomenti passati alla linea di comando.
 * @param argv Array di stringhe contenente gli argomenti della linea di comando.
 * 
 * @return int Restituisce 0 se il programma termina correttamente.
 */


int main(int argc, char *argv[])
{

	int i = 0, n;

	do
	{										   // ripeti
		printf("Inserisci un numero >= 0 : "); // scrivi "inserisci un num"
		scanf("%d", &n);					   // leggi n
	} while (n < 0);						   // finche n<0

	do
	{									   // ripeti
		printf("il numero vale: %d\n", i); // scrivi i
		i = i + 2;						   // i:=i+2
	} while (i <= n);					   // finche i<=n

	return 0;
}
