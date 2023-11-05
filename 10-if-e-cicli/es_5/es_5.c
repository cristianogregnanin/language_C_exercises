#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b, c, diff, nulli = 0, pari = 0, dispari = 0;

	do
	{
		printf("\ninserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);
		printf("inserisci c\n");
		scanf("%d", &c);
		diff = a - b;

		if (diff == 0)
		{
			nulli++;
		}

		if (diff % 2 == 0)
		{
			pari++;
		}
		else
		{
			dispari++;
		}

	} while (a + b >= c);

	printf("\nnulli: %d\n", nulli);
	printf("pari: %d\n", pari);
	printf("dispari: %d\n\n", dispari);

	return 0;
}
