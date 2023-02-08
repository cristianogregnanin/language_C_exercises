#include <stdio.h>

int main(int argc, char *argv[])
{

	int i, n;

	do
	{
		printf("Inserisci un numero >= 0 : ");
		scanf("%d", &n);
	} while (n < 0);

	i = -n;
	do
	{
		printf("il numero vale: %d\n", i);
		i = i + 1;
	} while (i <= n);

	return 0;
}
