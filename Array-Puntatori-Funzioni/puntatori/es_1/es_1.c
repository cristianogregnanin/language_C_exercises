/**
 * @brief Esempio dell'utilizzo dei puntatori in linguaggio C.
 * 
 * @param argc Numero argomenti riga di comando
 * @param argv Array di stringhe argomenti riga di comando
 * 
 * @return La funzione restituisce sempre 0.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

	int m = 11;
	int *p;

	printf("m vale: %d\n", m);
	printf("l'indirizzo di m è: %p\n\n", &m);

	p = &m;
	printf("*p referenzia il valore: %d\n", *p);
	printf("il contenuto di p è: %p\n", p);
	printf("Si osservi che il contenuto di p è l'indirizzo di m\n");
	printf("l'indirizzo di p è: %p\n\n", &p);

	return 0;
}
