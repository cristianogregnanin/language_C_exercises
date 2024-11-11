#include <stdio.h>
#include <math.h>

/**
 * @brief In un'acciaieria il semilavorato metallico grezzo viene prodotto con uno spessore di alcuni centimetri e viene successivamente lavorato passando
 *   per una serie di n laminatoi, ciascuno dei quali diminuisce lo spessore del 10%.
 *  A. Progettare un algoritmo per determinare lo spessore del laminato a partire dallo spessore del semilavorato grezzo e dal numero di laminatoi
 *   presenti nel processo di lavorazione.
 *  B. Modificare l'algoritmo precedente in modo che determini il numero di laminatoi necessari nel processo di lavorazione per ottenere un laminato di
 *   spessore definito a partie dallo spessore del semilavorato.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da riga di comando.
 * @return La funzione ritorna sempre 0.
 */

int main(int argc, char *argv[])
{
    double spessore_iniziale;
    int n;

    printf("Inserisci lo spessore iniziale del semilavorato (in cm): ");
    scanf("%lf", &spessore_iniziale);

    printf("Inserisci il numero di laminatoi: ");
    scanf("%d", &n);

    double spessore_finale = spessore_iniziale * pow(0.9, n);

    printf("Lo spessore finale del laminato è: %.2f cm\n", spessore_finale);

    return 0;
}
