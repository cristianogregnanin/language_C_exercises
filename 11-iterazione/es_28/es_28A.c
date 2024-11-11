#include <stdio.h>
#include <math.h>

/**
 * @brief Progettare un algoritmo per determinare lo spessore del laminato a partire dallo spessore del semilavorato grezzo e dal numero di laminatoi
 *  presenti nel processo di lavorazione.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
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
