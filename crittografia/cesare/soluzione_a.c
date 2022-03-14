#include <stdio.h>
#include <string.h>
#define DIM 100

/*Funzione che applica la codifica di cesare crittografando il messaggio spostando di posizione le varie lettere che compongono la parola in base al salto scelto (salto 3 di default)*/
void cesare(char s, int salto)
{
	char alfabeto[21] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z'};
	int i;

	for (i = 0; i < 21; ++i)
	{
		if (s == alfabeto[i])
			if (i >= 18)
				printf("%c", alfabeto[(i - 21) + salto]);
			else
				printf("%c", alfabeto[i + salto]);
	}
}

int main(int argc, char *argv[])
{

	char s[DIM];
	int i, lung;
	printf("Inserisci una stringa:\n");
	scanf("%s", s);
	lung = strlen(s); //alla variabile lung assegno il valore ritornato dalla funzione strlen() (funzione inclusa nella libreria <limits.h>) della stringa s

	/*Effettuo un ciclo che utilizzi la funzione cesare() per ogni lettera della stringa s*/
	for (i = 0; i < lung; ++i)
	{
		cesare(s[i], 3); //richiamo la funzione cesare() con salto 3
	}
	printf("\n");
	return 0;
}
