#include <stdio.h>

/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri pari minori o uguali a N.
 *
 * @param argc Numero di argomenti inseriti da riga di comando
 * @param argv Array di stringhe contenente gli argomenti inseriti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */

int main(int argc, char *argv[])
{

    int i = 0, n;

    do
    {
        printf("Inserisci un numero >= 0 : ");
        scanf("%d", &n);
    } while (n < 0);

    do
    {
        printf("il numero vale: %d\n", i);
        i = i + 2;
    } while (i <= n);

    return 0;
}

