#include <stdio.h>

int main(int argc, char *argv[])
{

	int n, j = 1, i;

	do
	{
		printf("Inserisci un numero > 0 : ");
		scanf("%d", &n);
	} while (n < 0);

	i = n - 1;

	do
	{
		printf("%d+%d=%d\n", j, i, n);
		j++;
		i--;
	} while (j <= n);

	return 0;
}
