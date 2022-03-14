#include <stdio.h>
#include <string.h>
#define DIM 100

void cesare(char s[], int salto)
{
	char alfabeto[21] = {'a',
						 'b',
						 'd',
						 'f',
						 'g'};
	int i, posizione;

	for (i = 0; i < strlen(s); i++)
	{
		posizione = ricerca(s[i], alfabeto);

		posizione = calcola(posizione);

		s[i] = alfabeto[posizione];
	}
}

int main(int argc, char *argv[])
{

	char s[DIM];

	printf("inserisci una stringa");
	scanf("%s", s);

	cesare(s, 3);

	printf("La stringa codificata è: %s\n", s);

	return 0;
}
