#include <stdio.h>

int main()
{

	int n1, n2, i;
	do
	{

		do
		{
			printf("Inserisci n1 >= 1 : ");
			scanf("%d", &n1);
		} while (n1 < 0);

		do
		{
			printf("Inserisci n2 >= 1 : ");
			scanf("%d", &n2);
		} while (n2 < 0);
		printf("\n\n");
	} while (n2 <= n1);

	i = n1;
	do
	{
		printf("%d\n", i);
		i = i + 1;
	} while (i < n2);

	return 0;
}
