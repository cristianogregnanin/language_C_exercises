#include <stdio.h>

/**
 * @brief Una pianta cresce ogni mese della metà di quanto è cresciuta il mese precedente (il primo mese cresce la metà dell'
 * altezza iniziale). Progettare l' algoritmo che calcoli l' altezza finale della pianta a partire dall' altezza iniziale e
 * dal numero di mesi.
 *
 * @param argc Il numero di argomenti da riga di comando.
 * @param argv Gli argomenti da riga di comando.
 *
 * @return ritorna a 0.
 */
int main(int argc, char *argv[])
{
    double altezzaIniziale;
    int mesi;

    printf("Inserisci l'altezza iniziale della pianta: ");
    scanf("%lf", &altezzaIniziale);
    printf("Inserisci il numero di mesi: ");
    scanf("%d", &mesi);

    double altezzaFinale = altezzaIniziale;
    double crescitaMensile = altezzaIniziale / 2.0;

    for (int i = 0; i < mesi; i++)
    {
        altezzaFinale = altezzaFinale + crescitaMensile;
        crescitaMensile = crescitaMensile / 2.0;
    }

    printf("L'altezza finale della pianta dopo %d mesi è: %.2f\n", mesi, altezzaFinale);

    return 0;
}
