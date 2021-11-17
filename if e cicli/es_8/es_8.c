#include <stdio.h>
#include <math.h>

int main()
{

	int n = 0;
	double somma;

	while (n >= 0)
	{
		printf("inserisci un numero maggiore o uguale di 0\n");
		scanf("%d", &n);

		if (n >= 0)
			somma = somma + sqrt(n);
		else
			printf("\nnumero errato\n");
	}

	printf("\nla somma è: %f\n\n", somma);

	return 0;
}
