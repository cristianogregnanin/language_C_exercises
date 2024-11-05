#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine
 * crescente i numeri compresi maggiori uguali di -N e minori uguali di N.
 *
 * @param argv, array con all'interno i valori che vengono passati da terminale
 * @param argc, Lunghezza dell'array argv
 *
 * @return 0 se il programma termina correttamente.
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
