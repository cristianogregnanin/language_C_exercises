#include <stdio.h>
#include <stdlib.h>

int older(int a[], int n)
{

	int i, max = a[0], pos;

	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			pos = i;
		}
	}

	return pos;
}

int main()
{

	char *names[] = {"Luca", "Lorenzo", "Davide", "Luca"};
	char *surnames[] = {"Montini", "Canali", "Fiorini", "Greggio"};
	int age[] = {22, 24, 24, 26};
	int n = (int)(sizeof(age) / sizeof(age[0]));

	int pos = older(age, n);

	printf("Il piu vecchio é: %s %s\n\n", names[pos], surnames[pos]);
}
