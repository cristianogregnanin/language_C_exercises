#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Ricerca la posizione di un numero nell'array di stringhe argv.
 *
 * Questa funzione cerca il numero specificato all'interno dell'array
 * `argv`, che contiene gli argomenti passati da riga di comando.
 * Se il numero è presente, restituisce la posizione del numero; altrimenti,
 * restituisce -1.
 *
 * @param n Numero di elementi nell'array argv (di solito argc).
 * @param argv Array di stringhe contenente gli argomenti da riga di comando.
 * @param numero Numero da ricercare all'interno dell'array.
 * @return La posizione del numero ricercato nell'array, oppure -1 se non trovato.
 */
int ricerca_posizione(int n, char *argv[], int numero)
{
	int i;

	for (i = 1; i < n; i++)
		if (numero == atoi(argv[i]))
			return i;

	return -1;
}

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
 * @param argv Array di stringhe (array di caratteri) contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce 0.
 */
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
