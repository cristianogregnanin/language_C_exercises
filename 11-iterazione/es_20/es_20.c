#include <stdio.h>
#include <math.h>

/**
 * @brief Funzione principale del programma.
 * 
 * Il programma chiede all'utente di inserire la massa iniziale, la costante di decadimento e il numero di anni.
 * Calcola la massa residua dopo un certo numero di anni (parte A).
 * Calcola il numero di anni necessari per ridurre la massa sotto 1 grammo (parte B).
 * 
 * @return int 0 se il programma termina correttamente.
 */
int main() {
    double massa_iniziale, costante_decay;
    int anni;

    // Inserimento dei dati per la parte A
    printf("Inserisci la massa iniziale (in grammi): ");
    scanf("%lf", &massa_iniziale);
    printf("Inserisci la costante di decadimento: ");
    scanf("%lf", &costante_decay);
    printf("Inserisci il numero di anni trascorsi: ");
    scanf("%d", &anni);

    double massa_residua = massa_iniziale * pow(1 - costante_decay, anni);
    printf("Massa residua dopo %d anni: %.2f grammi\n", anni, massa_residua);

    anni = 0;
    double massa_residua = massa_iniziale;
    while (massa_residua >= 1) {
        massa_residua *= (1 - costante_decay);
        anni++;
    }
    printf("Numero di anni necessari affinché la massa sia inferiore a 1 grammo: %d\n", anni);

    return 0;
}
