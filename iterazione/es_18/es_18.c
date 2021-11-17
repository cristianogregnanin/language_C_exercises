#include <stdio.h>

int main()
{

	int s1, h, m, s;
	do
	{
		printf("Inserisci un numero positivo: ");
		scanf("%d", &s1);

	} while (s1 < 1);

	m = s1 / 60;
	s = s1 % 60;
	h = m / 60;
	m = m % 60;

	printf("%dh %dm %ds\n\n", h, m, s);

	return 0;
}
