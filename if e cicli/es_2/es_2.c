#include <stdio.h>

int main()
{

	int a, b, p, somma = 0;

	do
	{
		printf("inserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);

		p = a * b;
		printf("il prodotto è: %d\n\n", p);

		somma = somma + p;
	} while (a != 0 && b != 0);

	printf("la somma è: %d\n\n", somma);
}
