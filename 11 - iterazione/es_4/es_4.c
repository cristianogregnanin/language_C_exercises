#include <stdio.h>

int main(int argc, char *argv[])
{

	int i; // dichiarazione della variabile i
	int n; // dichiarazione della variabile n

	do
	{										   //ripeti
		printf("Inserisci un numero >= 0 : "); //scrivi "inserisci un num"
		scanf("%d", &n);					   // leggi n
	} while (n < 0);						   // finche n<0

	i = 0; // i:=0     inizializzazione della variabile i a 0
	do
	{									   //ripeti
		printf("il numero vale: %d\n", i); //scrivi i
		i = i + 2;						   // i:=i+2
	} while (i <= n);					   //finche i<=n

	return 0; // fine
}
