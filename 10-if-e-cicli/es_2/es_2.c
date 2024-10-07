#include <stdio.h>

int main(int argc, char *argv[])
{

	int a, b, prodotto, somma = 0;

	do
	{
		printf("inserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);

		prodotto = a * b;
		printf("il prodotto è: %d\n\n", prodotto);

		somma = somma + prodotto;
	} while (a != 0 && b != 0);

	printf("la somma è: %d\n\n", somma);

	return 0;
}
