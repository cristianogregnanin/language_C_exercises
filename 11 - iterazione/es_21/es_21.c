#include <stdio.h>

int main(int argc, char *argv[])
{

	int n, i, resto;

	do
	{
		printf("Inserisci un numero > 1 : ");
		scanf("%d", &n);
	} while (n < 2);

	i = n - 1;
	do
	{
		resto = n % i;
		if (resto == 0)
		{
			printf("Il numero non è primo\n");
			return 0;
		}
		i = i - 1;
	} while (i > 1);

	printf("Numero Primo\n");

	return 0;
}
