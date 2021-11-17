#include <stdio.h>

int main()
{

	int i, n = 4;
	int a[n];

	for (i = 0; i < n; i++)
	{
		printf("Inserisci un numero :\n");
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("il numero in posizione %d è: %d\n", i, a[i]);
	}

	return 0;
}
