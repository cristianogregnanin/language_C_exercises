#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Si crei un programma che nel momento dell'esecuzione popoli l'array
 * argv[] con una serie di numeri. Esempio: $ ./a.out 1 5 9 6
 * Il programma deve quindi chiedere in input un numero e deve cercarlo 
 * all'interno dell'array argv.
 * Se il numero è presente il programma deve dare un messaggio positivo
 * e deve mostrare la posizione dell'elemento, altrimenti deve stampare a 
 * video: "numero non presente"
 * Suggerimento: si usi una funzione per ricercare la posizione dell'
 * elemento. Tale funzione deve tornare la posizione oppure -1.
 *
 * @param argc Numero di argomenti inseriti da riga di comando 
 * @param argv Array di stringhe contenente gli argomenti inseriti da riga di comando
 * 
 * @return La funzione restituisce 0.
 */

int ricerca_posizione(int n, char *argv[], int numero)
{
	int i;

	for (i = 1; i < n; i++)
		if (numero == atoi(argv[i]))
			return i;

	return -1;
}

int main(int argc, char *argv[])
{

	int numero;
	printf("Inserisci un numero da ricercare: ");
	scanf("%d", &numero);

	int posizione = ricerca_posizione(argc, argv, numero);

	if (posizione > 0)
		printf("numero %d trovato in posizione %d\n", numero, posizione);
	else
		printf("numero non trovato\n");

	return 0;
}
