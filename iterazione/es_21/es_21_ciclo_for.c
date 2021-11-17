#include <stdio.h>

int main()
{

	int n, i, resto;

	do
	{
		printf("Inserisci un numero > 1 : ");
		scanf("%d", &n);
	} while (n < 2);

	for (i = n - 1; i > 1; i = i - 1)
	{
		resto = n % i;
		if (resto == 0)
		{
			printf("Il numero non è primo\n");
			return 0;
		}
	}

	printf("Numero Primo\n");

	return 0;
}
