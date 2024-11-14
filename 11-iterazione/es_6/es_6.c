#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine
 * crescente i numeri compresi maggiori uguali di -N e minori uguali di N.
 *
 * @param argc Lunghezza dell'array argv (numero di argomenti passati da riga di comando)
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando
 *
 * @return la funzione ritorna sempre 0
 */

int main(int argc, char *argv[])
{
    int n;
    do
    {
        printf("Inserisci N: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = -n; i <= n; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}
