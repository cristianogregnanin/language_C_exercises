#include <stdio.h>

int isPari(int a[], int n)
{
	int i, j, cont;

	for (i = 0; i < n; i++)
	{
		cont = 0;

		for (j = 0; j < n; j++)
		{
			if (a[i] == a[j])
				cont++;
		}

		if ((cont % 2) != 0)
			return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{

	int pari[4];
	pari[0] = 1;
	pari[1] = 1;
	pari[2] = 2;
	pari[3] = 3;

	if (isPari(pari, 4) == 0)
		printf("L'array è pari\n");
	else
		printf("L'array è dispari\n");

	return 0;
}
