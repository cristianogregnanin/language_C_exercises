#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo maggiore di 1, generare e visualizzare il numero precedente.
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando
 *
 * @return la funzione ritorna sempre 0
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
