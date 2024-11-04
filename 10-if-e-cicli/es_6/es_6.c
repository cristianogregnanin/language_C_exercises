/**
 * @brief Progettare un algoritmo che effettui le seguenti operazioni:
 *	 	• legga da tastiera una coppia di valori interi A e B con A<B;
 *		• continui a leggere da tastiera una serie di valori interi, terminando
 *		  quando il valore letto è al di fuori dell’intervallo [A, B];
 *		• conteggi la media dei valori letti;
 *		• prima di terminare, stampi il valore calcolato.
 *
 * @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
 * @param argc Numero di argomenti passati attraverso la riga di comando
 *
 * @return La funzione restituisce 0
 */
#include <stdio.h>

int main(int argc, char *argv[])
{

    int i = 0, somma = 0, a, b, n;
    double media;
    do
    {
        printf("inserisci a\n");
        scanf("%d", &a);
        printf("inserisci b\n");
        scanf("%d", &b);
    } while (b < a);

    do
    {
        printf("inserisci un numero\n");
        scanf("%d", &n);

        if (n >= a && n <= b)
        {
            somma = somma + n;
            i++;
        }

    } while (n >= a && n <= b);
    media = (double)somma / (double)i;

    printf("\nla media è: %f\n\n", media);

    return 0;
}
