#include <stdio.h>

int main()
{

	int n, i;

	do
	{
		printf("Inserisci un numero >= 1 : ");
		scanf("%d", &n);
	} while (n < 0);

	i = n;
	do
	{
		printf("%d\n", i);
		i = i - 1;
	} while (i > 0);

	return 0;
}
