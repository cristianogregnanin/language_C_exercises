#include <stdio.h>

int verifica_input(int valore)
{
	if (valore > 0)
		return valore;
	else
		return -1;
}

int calcola_somma(int n1, int n2)
{
	return n1 + n2;
}

int main(int argc, char *argv[])
{

	int a, b, somma;

	do
	{
		printf("Inserisci a: ");
		scanf("%d", &a);
	} while (verifica_input(a) < 0);

	do
	{
		printf("Inserisci b: ");
		scanf("%d", &b);
	} while (verifica_input(b) < 0);

	somma = calcola_somma(a, b);

	printf("la somma è: %d\n", somma);

	return 0;
}
