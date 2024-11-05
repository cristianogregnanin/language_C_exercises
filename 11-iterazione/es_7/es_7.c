#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo maggiore di 1, generare e visualizzare il numero precedente.
 *
 * @param argc intero che da la lunghezza dell'array argv
 * @param argv Array che salva i valori mandati in input dal terminale quando si runna il programma
 *
 * @return se il programma funziona ritorna 0
 */
int main(int argc, char *argv[])
{

    int n;

    do
    {
        printf("Inserisci un numero >= 1 : ");
        scanf("%d", &n);
    } while (n < 1);

    n = n - 1;

    printf("Il numero precedente è: %d", n);

    return 0;
}
