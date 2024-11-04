#include <stdio.h>
#include <math.h>

/**
 * @brief Calcola la massa residua di un materiale radioattivo dopo un certo numero di anni.
 * 
 * La formula usata è: M_t = M_0 * (1 - k)^t
 * dove M_t è la massa residua, M_0 è la massa iniziale, k è la costante di decadimento
 * e t è il numero di anni trascorsi.
 * 
 * @param massa_iniziale Massa iniziale del materiale (in grammi).
 * @param costante_decay Costante di decadimento del materiale.
 * @param anni Numero di anni trascorsi.
 * @return double La massa residua del materiale dopo il numero di anni specificato.
 */
double calcola_massa_residua(double massa_iniziale, double costante_decay, int anni) {
    return massa_iniziale * pow(1 - costante_decay, anni);
}
/**
 * @brief Calcola il numero di anni necessari affinché la massa residua sia inferiore a 1 grammo.
 * 
 * La funzione parte dalla massa iniziale e riduce iterativamente la massa in base alla costante
 * di decadimento fino a quando la massa residua non scende sotto 1 grammo.
 * 
 * @param massa_iniziale Massa iniziale del materiale (in grammi).
 * @param costante_decay Costante di decadimento del materiale.
 * @return int Il numero di anni necessario affinché la massa residua sia inferiore a 1 grammo.
 */
int anni_per_massa_inferiore_1g(double massa_iniziale, double costante_decay) {
    int anni = 0;
    double massa_residua = massa_iniziale;
    while (massa_residua >= 1) {
        massa_residua *= (1 - costante_decay);
        anni++;
    }
    return anni;
}
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

    double massa_residua = calcola_massa_residua(massa_iniziale, costante_decay, anni);
    printf("Massa residua dopo %d anni: %.2f grammi\n", anni, massa_residua);

    int anni_necessari = anni_per_massa_inferiore_1g(massa_iniziale, costante_decay);
    printf("Numero di anni necessari affinché la massa sia inferiore a 1 grammo: %d\n", anni_necessari);

    return 0;
}