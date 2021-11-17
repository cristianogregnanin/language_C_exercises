#include <stdio.h>

int main()
{

	int n1, n2, i, prodotto;
	do
	{
		printf("Inserisci n1 >= 1 : ");
		scanf("%d", &n1);
	} while (n1 < 1);

	do
	{
		printf("Inserisci n2 >= 1 : ");
		scanf("%d", &n2);
	} while (n2 < 1);
	printf("\n\n");

	i = 0;
	prodotto = 0;
	do
	{
		prodotto = prodotto + n1;
		i = i + 1;
	} while (i < n2);

	printf("Il prodotto fra N1 e N2 è: %d\n\n", prodotto);
	return 0;
}
