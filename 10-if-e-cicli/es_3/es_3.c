#include <stdio.h>
#include <math.h>  // Inclusione della libreria math

/**
 * @file calcola_area.c
 * @brief Calcola l'area di un cerchio dato il raggio.
 *
 * Questo programma richiede all'utente di inserire il raggio di un cerchio
 * e poi calcola e stampa l'area corrispondente utilizzando la formula
 * A = π * r^2.
 *
 * @param raggio Il raggio del cerchio fornito dall'utente.
 * @return L'area del cerchio calcolata.
 */

int main() {
    double raggio;  
    double area;    

    // Richiesta dell'input all'utente
    printf("Inserisci il raggio del cerchio: ");
    scanf("%lf", &raggio);

    // Calcolo dell'area usando la formula A = 3,14 * r^2
    area = M_PI * pow(raggio, 2);  // Utilizza M_PI e pow per calcolare l'area

    // Stampa dell'area
    printf("L'area del cerchio con raggio %.2f è %.2f\n", raggio, area);

    return 0;  
}