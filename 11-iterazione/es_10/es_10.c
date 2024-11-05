/**
 * @brief Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
 * Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.
 *
 * Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
 * 1.	La media dell’incasso delle bevande 
 * 2.	La media dell’incasso della ristorazione
 * 3.	Deve indicare se sono state vendute più bevande o più ristorazioni
 * 
 * @param argc numero di argomenti passati da riga di comando
 * @param argv argomenti passati da riga di comando
 * 
 * @return la funzione restituisce 0
 */
#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei
 * primi N numeri interi. 
 * 
 * @param argc Numero di argomenti da riga di comando (non utilizzato).
 * @param argv Array di stringhe contenente gli argomenti da riga di comando (non utilizzato).
 *
 * @return Restituisce 0 se l'esecuzione del programma è andata a buon fine.
 */

int main(int argc, char *argv[])
{

	int n, i, somma;
	do
	{
		printf("Inserisci un numero positivo: \n");
		scanf("%d", &n);

	} while (n < 0);

	somma = 0;
	i = n;
	do
	{
		somma = somma + i;
		i = i - 1;
	} while (i > 0);
	printf("La somma vale: %d\n\n", somma);

	return 0;
}
