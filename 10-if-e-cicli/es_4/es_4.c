#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{

	int a, b;
	double r;

	do
	{
		printf("inserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);

		if (a < b)
		{
			if (a == 0)
			{
				printf("non si puo' dividere un numero per 0\n");
				break;
			}
			r = (double)b / (double)a;
		}
		else
		{
			if (b == 0)
			{
				printf("non si puo' dividere un numero per 0\n");
				break;
			}
			r = (double)a / (double)b;
		}

		if (r >= 0)
		{
			r = sqrt(r);
			printf("\n\nradice quadrata del rapporto: %f\n\n", r);
		}
		else
		{
			printf("\n\nnon è possibile calcolare la radice di un numero negativo\n\n");
		}
	} while (r >= 0);

	return 0;
}
