#include <stdio.h>

/**
* @brief Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma ripetuta, il prodotto dei due numeri e visualizzarli.
*
*
* @param argc Numero di argomenti da riga di comando (non utilizzato).
* @param argv Array di stringhe contenente gli argomenti da riga di comando (non utilizzato).
*
* @return Restituisce 0 se l'esecuzione del programma e' andata a buon fine.
*/

int main(int argc, char *argv[])
{

    int n1, n2, i = 0, prodotto = 0;
    do
    {
        printf("Inserisci n1 >= 1 : ");
        scanf("%d", &n1);
    } while (n1 < 1);

    do
    {
        printf("Inserisci n2 >= 1 : ");
        scanf("%d", &n2);
    } while (n2 < 1);
    printf("\n\n");

    do
    {
        prodotto = prodotto + n1;
        i = i + 1;
    } while (i < n2);

    printf("Il prodotto fra N1 e N2 è: %d\n\n", prodotto);
    return 0;
}
