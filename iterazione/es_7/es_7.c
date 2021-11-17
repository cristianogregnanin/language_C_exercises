#include <stdio.h>

int main()
{

	int n;

	do
	{
		printf("Inserisci un numero >= 1 : ");
		scanf("%d", &n);
	} while (n < 1);

	n = n - 1;

	printf("Il numero precedente è: %d", n);

	return 0; // fine
}
