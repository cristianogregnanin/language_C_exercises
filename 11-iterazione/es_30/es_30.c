#include <stdio.h>

/**
 * @brief Verifica, dati due numeri interi, che n1 sia il quadrato di n2.
 *
 * La funzione prende in input dall'utente i due valori, effettuando
 * un controllo e un reinserimento in caso di valori minori o uguali
 * a 0. Successivamente viene verificato se il primo valore e' uguale
 * e viene stampato un risultato a seconda del risultato del controllo.
 *
 * @param argv Array di stringhe contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */
int main(int argc, char *argv[])
{

	int n1, n2;

	do
	{
		printf("Inserisci un numero > 0 : ");
		scanf("%d", &n1);
	} while (n1 < 1);

	do
	{
		printf("Inserisci un numero > 0 : ");
		scanf("%d", &n2);
	} while (n2 < 1);

	if (n1 == (n2 * n2))
		printf("%d è il quadrato di %d\n\n", n1, n2);
	else
		printf("%d non è il quadrato di %d\n\n", n1, n2);

	return 0;
}
