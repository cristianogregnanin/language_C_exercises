/**
 * @brief Dati due numeri si scriva in linguaggio C una funzione di tipo void denominata scambia,
 * 		  che dati in input 2 numeri li scambi.
 *
 * @param a Puntatore alla prima variabile intera da scambiare.
 * @param b Puntatore alla seconda variabile intera da scambiare.
 *
 * @return Nessun valore restituito. La funzione modifica direttamente i valori delle variabili passate tramite i puntatori.
*/

#include <stdio.h>

void scambia(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

int main(int argc, char *argv[])
{

	int a = 10, b = 15;

	scambia(&a, &b);

	printf("dopo lo scambio a vale: %d\n", a);
	printf("dopo lo scambio b vale: %d\n", b);
}
