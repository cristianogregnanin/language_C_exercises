/**
 * @brief In c gli array vengono passati come parametri alle funzioni 
			per riferimento e non per copia. Cio implica che se una funzione
			modifica l'array allora anche l'array originale sarà modificato.
			Inoltre, in linguaggio C il nome dell'array coincide con l'indirizzo
			del primo elemento dell'array.
			Quindi in C dato un array vale che: 
			int A[DIM];
			A == &A == &A[0]
 * 
 * La funzione principale inizializza un array di interi e assegna valori ai suoi elementi usando la notazione dei puntatori.
 * Stampa gli indirizzi dell'array `numeri` e degli elementi dell'array. Infine, stampa i valori degli elementi
 * dell'array usando l'aritmetica dei puntatori.

 * 
 * @param argc Numero argomenti riga di comando
 * @param argv Array di stringhe argomenti riga di comando
 * @return La funzione restituisce sempre 0
 */

#include <stdio.h>

// questa versione usa la sintassi con gli * anzichè le [] 
int main(int argc, char *argv[])
{
    
    int numeri[5];
    *numeri = 0;
    *(numeri+1) = 10;
    *(numeri+2) = 20;
    *(numeri+3) = 30;
    *(numeri+4) = 40;
    
    printf("Indirizzo dell'array numeri: %p\n", numeri);
    printf("Indirizzo dell'array numeri: %p\n", &numeri);
    printf("Indirizzo di numeri[0]: %p\n", &numeri[0]);
    
    for (int i = 0; i < 5; i++)
    {
        printf("%p\n", &numeri[i]);
    }
    
     for (int i = 0; i < 5; i++)
    {
        printf("numeri[%d]: %d\n", i, *(numeri + i));
    }
    
    return 0;
}
