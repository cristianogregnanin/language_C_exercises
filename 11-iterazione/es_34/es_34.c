#include <stdio.h>

/**
 * @brief Una pianta cresce ogni mese della metà di quanto è cresciuta il mese precedente (il primo mese cresce la metà dell' 
 * altezza iniziale). Progettare l' algoritmo che calcoli l' altezza finale della pianta a partire dall' altezza iniziale e 
 * dal numero di mesi.
 *
 * Questa funzione simula la crescita di una pianta, dove ogni mese la pianta cresce
 * della metà della crescita del mese precedente.
 * 
 * @param argc Il numero di argomenti da riga di comando.
 * @param argv Gli argomenti da riga di comando.
 *
 * @return ritorna a 0.
 */
int main(int argc, char *argv[]) {
    //l'altezza iniziale della pianta
    double altezzaIniziale; 
    //il numero di mesi di crescita
    int mesi;              

    //input dell'utente
    printf("Inserisci l'altezza iniziale della pianta: ");
    scanf("%lf", &altezzaIniziale);
    printf("Inserisci il numero di mesi: ");
    scanf("%d", &mesi);

    //inizializza l'altezza finale
    double altezzaFinale = altezzaIniziale; 
    //crescita del primo mese
    double crescitaMensile = altezzaIniziale / 2.0; 

    for (int i = 0; i < mesi; i++) {
        //aggiunge la crescita mensile
        altezzaFinale += crescitaMensile; 
        //crescita per il mese successivo è la metà di quella attuale
        crescitaMensile /= 2.0; 
    }

    //stampa l'altezza finale
    printf("L'altezza finale della pianta dopo %d mesi è: %.2f\n", mesi, altezzaFinale);

    return 0;
}
