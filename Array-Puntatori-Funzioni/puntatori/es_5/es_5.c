#include <stdio.h>

/**
 * @brief funzione che stampa il valore e l'indirizzo di una variabile di tipo int
 *
 * @param m variabile che contiene il valore e l'indirizzo da stampare
 *
 */
void indirizzamento_variabile(int m)
{
	printf("m dentro alla funzione vale: %d\n", m);
	printf("l'indirizzo di m dentro alla funzione è: %p\n\n", &m);
}

/**
 * @brief funzione che stampa il valore e l'indirizzo di un array di tipo int passato per funzione
 *
 * @param a array che continene il valore e l'indirizzo del primo elemento da stampare
 *
 */
void indirizzamento_array(int a[])
{
	printf("l'indirizzo di a dentro alla funzione è: %p\n", a);
	printf("l'indirizzo di a dentro alla funzione è: %p\n\n", &a[0]);
}

/**
 * @brief esercizio spiegazione puntatori
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando, contenente anche la stringa e il carattere da contare
 *
 * @return la funzione ritorna sempre 0
 */
int main(int argc, char *argv[])
{
	int m = 11;
	printf("m vale: %d\n", m);
	printf("l'indirizzo di m è: %p\n\n", &m);

	indirizzamento_variabile(m);

	int a[2];
	printf("l'indirizzo di a è: %p\n", a);
	printf("l'indirizzo di a è: %p\n", &a);
	printf("l'indirizzo di a è: %p\n\n", &a[0]);

	indirizzamento_array(a);

	return 0;
}
