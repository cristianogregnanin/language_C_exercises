#include <stdio.h>

void indirizzamento_variabile(int m)
{
	printf("m dentro alla funzione vale: %d\n", m);
	printf("l'indirizzo di m dentro alla funzione è: %p\n\n", &m);
}

void indirizzamento_array(int a[])
{
	printf("l'indirizzo di a dentro alla funzione è: %p\n", a);
	printf("l'indirizzo di a dentro alla funzione è: %p\n\n", &a[0]);
}

int main()
{
	int m = 11;
	printf("m vale: %d\n", m);
	printf("l'indirizzo di m è: %p\n\n", &m);

	indirizzamento_variabile(m);

	int a[2];
	printf("l'indirizzo di a è: %p\n", a);
	printf("l'indirizzo di a è: %p\n", &a);
	printf("l'indirizzo di a è: %p\n\n", &a[0]);

	indirizzamento_array(a);
}
