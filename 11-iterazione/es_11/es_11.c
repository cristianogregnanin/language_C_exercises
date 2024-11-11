#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei primi N numeri dispari.
 *
 * @param argc Numero di argomenti da riga di comando (non utilizzato).
 * @param argv Array di argomenti da riga di comando (non utilizzato).
 *
 * @return Se il programma termina correttamente restituisce 0.
 */

int main(int argc, char *argv[])
{
    int n, i = 1, somma = 0;
    do
    {
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &n);

    } while (n < 0);

    do
    {
        somma = somma + i;
        i = i + 2;
    } while (i < n);
    printf("La somma vale: %d\n\n", somma);

    return 0;
}