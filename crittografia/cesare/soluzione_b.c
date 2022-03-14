#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM 100
#define DIM_ALFABETO 21

int ricerca(char s, char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (!isspace(s))
		{
			if (s == a[i])
				return i;
		}
	}
	return -1;
}

int calcola(int pos, int s)
{
	int border = DIM_ALFABETO - s;
	if (pos >= border)
		return pos % border;
	else
		return pos + s;
}

void cesare(char s[], int salto)
{
	char alfabeto[21] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z'};
	int i, posizione;

	for (i = 0; i < strlen(s); i++)
	{
		posizione = ricerca(s[i], alfabeto);

		if (posizione >= 0)
		{
			posizione = calcola(posizione, salto);

			s[i] = alfabeto[posizione];
		}
	}
}

int main(int argc, char *argv[])
{

	char s[DIM];

	printf("inserisci una stringa\n");
	scanf("%[^\n]s", s);

	cesare(s, 4);

	printf("La stringa codificata è: %s\n", s);

	return 0;
}
