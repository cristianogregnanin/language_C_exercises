#include <stdio.h>
#include <math.h>

/**
 * @brief 29. Nella disintegrazione atomica dei materiali radioattivi la massa perduta nel periodo di un anno è data dal prodotto della massa residua per una costante di decadimento caratteristica del tipo di materiale.
 * A. Progettare un algoritmo che calcoli, a partire dai valori della massa iniziale espressa in grammi, della costante di decadimento e del numero di anni trascorsi, la massa residua di materiale.
 * B. Modificare l’algoritmo precedente in modo che, a partire dalla massa iniziale espressa in grammi e dalla costante di decadimento, determini il numero di anni necessario prima che la massa residua di materiale sia inferiore a 1 g.
 *
 * @return int 0 se il programma termina correttamente.
 */

int main()
{
    double massa_iniziale, costante_decay;
    int anni;

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
        massa_residua = massa_residua * (1 - costante_decay);
        anni++;
    }
    printf("Numero di anni necessari affinché la massa sia inferiore a 1 grammo: %d\n", anni);

    return 0;
}
