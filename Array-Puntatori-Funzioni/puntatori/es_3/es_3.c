/**
 * @brief In C gli array vengono passati come parametri alle funzioni 
 * per riferimento e non per copia. Cio' implica che se una funzione
 * modifica l'array allora anche l'array originale sarà modificato.
 * Inoltre, in linguaggio C il nome dell'array coincide con l'indirizzo
 * del primo elemento dell'array.
 * Quindi in C dato un array vale che: 
 * int A[DIM];
 * A == &A == &A[0]
 * 
 * La funzione principale stampa gli indirizzi dell'array `a` in diversi modi:
 * - Come nome dell'array
 * - Come indirizzo dell'array
 * - Come indirizzo del primo elemento dell'array
 *
 * Questi indirizzi sono identici, il che implica che quando un array viene passato
 * a una funzione, le modifiche a quell'array avranno effetto sull'array originale.
 * 
 * @param argc Numero argomenti riga di comando
 * @param argv Array di stringhe argomenti riga di comando
 * 
 * @return La funzione restituisce sempre 0
 */

#include <stdio.h>
#define DIM 20

int main(int argc, char *argv[])
{
	int a[DIM];

	printf("l'indirizzo di A é: %p\n", a);
	printf("l'indirizzo di A é: %p\n", &a);
	printf("l'indirizzo di A é: %p\n", &a[0]);

	printf("\nCio implica che se passo un'array ad una funzione, se essa lo modifica questa avrà effetto sull'array originale.");
}
