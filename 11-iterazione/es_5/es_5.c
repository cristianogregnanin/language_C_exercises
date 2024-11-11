#include <stdio.h>

/**
 * @brief Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
 * visualizzare in ordine crescente i numeri interi compresi
 * nell'intervallo chiuso [N1,N2].
 * @param argc Numero di argomenti passati attraverso la riga di comando
 * @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
 * @return la funzione restituisce 0
 */

int main(int argc, char *argv[])
{

    int n1, n2;
    /*
     * Itero finche non è rispettata la condizione
     * tale per cui n1 e n2 devono essere > 0
     * e anche n2>n1
     */
    do
    {

        printf("inserisci n1\n");
        scanf("%d", &n1);
        printf("inserisci n2\n");
        scanf("%d", &n2);
        printf("\n");
    } while (n1 < 0 || n2 <= n1);

    while (n1 <= n2)
    {
        printf("%d\n", n1);
        n1++;
    }

    return 0;
}
