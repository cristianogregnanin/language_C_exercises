
#include <stdio.h>

/**
 * @brief Verifica se un valore intero è positivo.
 *
 * Questa funzione controlla se il valore passato come parametro è maggiore di zero.
 * Se il valore è positivo, la funzione restituisce il valore stesso; altrimenti, 
 * restituisce -1.
 *
 * @param valore Il valore intero da verificare.
 * @return Il valore originale se positivo, oppure -1 se il valore è minore o uguale a zero.
 */
int verifica_input(int valore)
{
	if (valore > 0)
		return valore;
	else
		return -1;
}

/**
 * @brief calcola la somma di due numeri  
 * 
 * @param n1 primo numero
 * @param n2 secondo numero 
 * @return Restituisce la somma tra n1 e n2
 * 
 */
int calcola_somma(int n1, int n2)
{
	return n1 + n2;
}

/**
 * @brief Leggere in input da tastiera due numeri maggiori di 0 e farne la somma. 
 * 
 * @param argc dimensione dell'array argv
 * @param argv argomenti che prende da riga di comando
 * @return Restituisce 0 se l'esecuzione ha successo.
 */
int main(int argc, char *argv[])
{

	int a, b, somma;

	do
	{
		printf("Inserisci a: ");
		scanf("%d", &a);
	} while (verifica_input(a) < 0);

	do
	{
		printf("Inserisci b: ");
		scanf("%d", &b);
	} while (verifica_input(b) < 0);

	somma = calcola_somma(a, b);

	printf("la somma è: %d\n", somma);

	return 0;
}
