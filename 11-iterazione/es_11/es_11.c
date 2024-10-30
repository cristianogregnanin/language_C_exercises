/**
 * @brief Dato N un numero intero positivo, calcolare e visualizzare la somma dei primi N numeri dispari.
 *
 * @param argc Numero di argomenti da riga di comando (non utilizzato in questo programma).
 * @param argv Array di argomenti da riga di comando (non utilizzato in questo programma).
 *
 * @return 0 Se il programma termina correttamente.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i, somma;
    do
    {
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &n);
    } while (n < 0);

    somma = 0;
    i = 1;
    do
    {
        somma = somma + i;
        i = i + 2;
    } while (i < n);
    printf("La somma vale: %d\n\n", somma);

    return 0;
}
