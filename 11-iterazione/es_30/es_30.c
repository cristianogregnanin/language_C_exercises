#include <stdio.h>

/**
 * @brief Dati due numeri interi positivi N1 e N2, verificare se N1 e' il quadrato di N2. 
 * 
 * @param argc Numero di argomenti da riga di comando
 * @param argv Array di stringhe contenente gli argomenti da riga di comando
 * 
 * @return La funzione ritorna sempre 0.
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
