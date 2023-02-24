#include <stdio.h>
#define DIM 4

int main(int argc, char *argv[])
{

	int i;
	int a[DIM];

	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci un numero :");
		scanf("%d", &a[i]);
	}

	for (i = DIM - 1; i >= 0; i--)
	{
		printf("il numero in posizione %d è: %d\n", i, a[i]);
	}

	return 0;
}
