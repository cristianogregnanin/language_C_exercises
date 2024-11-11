#include <stdio.h>

/**
 * @brief Scambia i valori di due variabili intere.
 *
 * Questa funzione prende in input due puntatori a interi e scambia i valori
 * delle variabili cui i puntatori fanno riferimento.
 *
 * @param a Puntatore alla prima variabile intera da scambiare.
 * @param b Puntatore alla seconda variabile intera da scambiare.
 */
void scambia(int *a, int *b)
{
    int swap = *a;
    *a = *b;
    *b = swap;
}

/**
 * @brief Dati due numeri si scriva in linguaggio C una funzione di tipo void denominata scambia,
 * che dati in input 2 numeri li scambi.
 *
 * @param argc Numero di argomenti passati da linea di comando (non utilizzato in questo caso).
 * @param argv Array di stringhe che rappresentano gli argomenti passati da linea di comando (non utilizzato in questo caso).
 *
 * @return Restituisce 0 per indicare che il programma è terminato correttamente.
 */
int main(int argc, char *argv[])
{
    int a = 10, b = 15;
    scambia(&a, &b);

    printf("dopo lo scambio a vale: %d\n", a);
    printf("dopo lo scambio b vale: %d\n", b);
    return 0;
}
