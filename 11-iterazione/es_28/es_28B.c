#include <stdio.h>
#include <math.h>

/**
 * @brief Modificare l'algoritmo precedente in modo che determini il numero di laminatoi necessari nel processo di lavorazione per ottenere un laminato di
        spessore definito a partie dallo spessore del semilavorato.
 * 
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 * @return La funzione ritorna sempre 0. 
 */

int calcola_numero_laminatoi(double spessore_iniziale, double spessore_finale) {
    int n = 0;

    while (spessore_iniziale > spessore_finale) {
        spessore_iniziale *= 0.9;
        n++;
    }

    return n;
}

int main(int argc, char*argv[]) {
    double spessore_iniziale, spessore_finale;

    printf("Inserisci lo spessore iniziale del semilavorato (in cm): ");
    scanf("%lf", &spessore_iniziale);

    printf("Inserisci lo spessore finale desiderato (in cm): ");
    scanf("%lf", &spessore_finale);

    int numero_laminatoi = calcola_numero_laminatoi(spessore_iniziale, spessore_finale);

    printf("Il numero di laminatoi necessari è: %d\n", numero_laminatoi);

    return 0;
}
