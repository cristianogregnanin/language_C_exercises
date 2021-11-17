#include <stdio.h>

int main()
{

	int n, i = 0; //dichiarazione variabili di tipo intero

	do
	{									   //ripeti
		printf("inserisci un numero: \n"); //Scrivi inserisci un numero
		scanf("%d", &n);				   //leggi n
	} while (n <= 0);					   //finche n<=0

	do
	{					   //ripeti
		i++;			   //i:=i+1
		printf("%d\n", i); //scrivi i

	} while (i < n); //finche i>n

	return 0; //la funzione main deve ritornare un valore int
}
