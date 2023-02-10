#include <stdio.h>

int main(int argc, char *argv[])
{

	int n, i = 0;
	do
	{
		printf("inserisci un numero: \n");
		scanf("%d", &n);
	} while (n <= 0);

	do
	{
		i++;
		printf("%d\n", i);

	} while (i < n);

	return 0;
}
