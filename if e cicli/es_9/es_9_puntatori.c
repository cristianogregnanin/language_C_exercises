#include <stdio.h>
#include <limits.h>

void calcola_min_max(int a, int b, int c, int *min, int *max)
{
	if (a < b && b < c)
	{

		if (a < *min)
			*min = a;
		if (c > *max)
			*max = c;
	}
	else
	{
		printf("terna non valida\n");
	}
}

int main()
{
	int a, b, c;
	int min = INT_MAX, max = 0;

	do
	{
		printf("\ninserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);
		printf("inserisci c\n");
		scanf("%d", &c);

		calcola_min_max(a, b, c, &min, &max);

	} while (a >= 0 && b >= 0 && c >= 0);

	printf("\nmax: %d\n", max);
	printf("\nminimo: %d\n\n", min);

	return 0;
}
