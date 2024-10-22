/**
 * @brief Genera e visualizza in ordine decrescente i numeri compresi da due numeri  
 *
 * Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
 * visualizzare in ordine decrescente i numeri compresi tra N1 e N2.
 *
 * @return 0 in caso di successo.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

	int n1, n2, i;
	do
	{

		do
		{
			printf("Inserisci il primo numero >= 1 : ");
			scanf("%d", &n1);
		} while (n1 < 0);

		do
		{
			printf("Inserisci il secondo numero >= 1 : ");
			scanf("%d", &n2);
		} while (n2 < 0);
		printf("\n\n");
	} while (n2 <= n1);

	i = n1;
	do
	{
		printf("%d\n", i);
		i = i + 1;
	} while (i < n2);

	return 0;
}