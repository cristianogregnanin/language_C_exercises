#include <stdio.h>
#include <string.h>

/**
 * @brief Funzione che conta le occorrenze di un carattere all'interno di una stringa
 * 
 * @param string stringa (array di caratteri) da analizzare
 * @param carattere carattere di cui si contano le occorrenze all'interno della stringa
 * @param k puntatore ad una variabile intera utilizzata per contare il numero di occorrenze del carattere nella stringa
*/
void ricerca(char string[], char carattere, int *k)
{
	for (int i = 0; i < strlen(string); i++)
		if (string[i] == carattere)
			(*k)++;
}

/**
 * @brief Conteggio occorrenze carattere in una stringa
 * Si scriva una funzione in linguaggio C che riceva in input una stringa
 * e un carattere.
 * La funzione deve contare le occorrenze del carattere all'interno della
 * stringa.
 * La funzione deve necessariamente essere di tipo void.
 * Nel main si richiami la funzione e si mostri a video il risultato.

 * Esempio di esecuzione:
 * $ ./a.out pippo p
 * Il carattere p compare 3 volte in pippo

 * $ ./a.out ciao b
 * Il carattere b compare 0 volte in ciao
 * 
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando, contenente anche la stringa e il carattere da contare
 * 
 * @return la funzione ritorna sempre 0
*/
int main(int argc, char *argv[])
{

	int contatore = 0;
	ricerca(argv[1], argv[2][0], &contatore);

	printf("Il carattere %s compare %d volte in %s\n", argv[2], contatore, argv[1]);

	return 0;
}
