#include <stdio.h>

int main()
{

	int n1, n2;
	do
	{
		do
		{
			printf("inserisci n1\n");
			scanf("%d", &n1);
		} while (n1 < 0);

		do
		{
			printf("inserisci n2\n");
			scanf("%d", &n2);
		} while (n2 < 0);
	} while (n2 <= n1);

	do
	{
		printf("%d\n", n1);
		n1++; //i=i+1
	} while (n1 <= n2);
}
