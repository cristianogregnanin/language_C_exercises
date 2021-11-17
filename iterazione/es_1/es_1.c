#include <stdio.h>

int main()
{

	int n, s; //dichiarazione variabili di tipo intero

	do
	{									   //ripeti
		printf("inserisci un numero: \n"); //Scrivi inserisci un numero
		scanf("%d", &n);				   //leggi n
	} while (n <= 0);					   //finche n<=0

	s = n + 1;
	printf("il successivo vale: %d\n\n", s); //scrivi s

	return 0; //la funzione main deve ritornare un valore int
}
