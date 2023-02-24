#include <stdio.h>

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

		if (a > b)
			r = (double)b / (double)a;
		else
			r = (double)a / (double)b;
		printf("\n\tIl risultato è: %f\n\n", r);
	} while (a != 0 && b != 0);

	return 0;
}
