/**
 * @file birreria.c
 * @brief Gestione incassi di una birreria.
 *
 * Questo programma permette alla cassiera di inserire le consumazioni servite
 * e calcolare le medie degli incassi per bevande e ristorazione. Quando
 * viene inserita la stringa "esci", il programma mostra le informazioni
 * richieste.
 *
 * @details
 * Le consumazioni possono essere di due tipi:
 * - Bevande
 * - Ristorazione
 *
 * La cassiera può inserire un importo per ciascuna consumazione e, alla
 * fine, il programma calcola la media degli incassi e indica quale tipo
 * di consumazione è stato venduto di più.
 *
 * @author Mattia Crepaldi
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    double bevande = 0, ristorazione = 0, sommab = 0, sommar = 0, mediab = 0, mediar = 0;
    double countb = 0, countr = 0;  ///< Contatori per bevande e ristorazione
    char scelta[10];  ///< Stringa per la scelta dell'utente
    
    do {
        printf("Bevanda (0), ristorazione (1) o uscita (esci)? ");
        scanf("%s", scelta);  ///< Chiede la scelta all'utente
        
        // Controlla se l'input è per bevande
        if (strcmp(scelta, "0") == 0) {
            countb++;  ///< Incrementa il contatore delle bevande
            printf("BEVANDA\n");
            printf("Inserisci l'importo di una consumazione: ");
            scanf("%lf", &bevande);  ///< Legge l'importo della bevanda
            sommab += bevande;  ///< Aggiunge l'importo al totale delle bevande
            mediab = sommab / countb;  ///< Calcola la media delle bevande
        }
        
        // Controlla se l'input è per ristorazione
        if (strcmp(scelta, "1") == 0) {
            countr++;  ///< Incrementa il contatore delle ristorazioni
            printf("RISTORAZIONE\n");
            printf("Inserisci l'importo di una consumazione: ");
            scanf("%lf", &ristorazione);  ///< Legge l'importo della ristorazione
            sommar += ristorazione;  ///< Aggiunge l'importo al totale della ristorazione
            mediar = sommar / countr;  ///< Calcola la media delle ristorazioni
        }
        
        // Controlla se l'input è "esci"
        if (strcmp(scelta, "esci") == 0) {
            break;  ///< Esce dal ciclo
        }
        
        else {
            printf("Scelta non valida\n");
        }
        
    } while (1);  ///< Ciclo infinito, controllato da "break"
    
    // Stampa i risultati
    printf("Media incasso delle bevande: %lf\n", mediab);
    printf("Media incasso della ristorazione: %lf\n", mediar);

    // Confronta il numero di bevande e ristorazioni vendute
    if (countr > countb) {
        printf("Sono state vendute più ristorazioni\n");
    } 
    else if (countb > countr) {
        printf("Sono state vendute più bevande\n");
    } else {
        printf("Sono state vendute uguali ristorazioni e bevande\n");
    }
    
    return 0;
}

