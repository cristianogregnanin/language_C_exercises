#include <stdio.h>

void scambia(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

int main(int argc, char *argv[])
{

	int a = 10, b = 15;

	scambia(&a, &b);

	printf("dopo lo scambio a vale: %d\n", a);
	printf("dopo lo scambio b vale: %d\n", b);
}
