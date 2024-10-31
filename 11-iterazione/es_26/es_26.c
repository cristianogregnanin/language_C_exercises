#include <stdio.h>
/**
 * @brief Il filosofo Zenone di Elea motivava il fatto che il moto è solo un'illusione con la seguente argomentazione: 
 * «dovendo percorrere una certa distanza si dovra coprire con un primo spostamento meta della distanza, 
 * con un secondo spostamento metà della distanza rimanente, 
 * con un terzo spostamento metà della distanza ancora rimanente e cosi via senza arrivare mai a destinazione». 
 * Progettare un algoritmo in C che, data la distanza da percorrere e il numero di spostamenti effettuati, calcoli la distanza effettivamente coperta.
 * 
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv  Array di stringhe degli argomenti passati da righa di comando.
 * @return La funzione ritorna sempre 0.
 */
int main(int argc, char *argv[]) 
{
    
    double distanza;
    int num_spostamenti;
    

    printf("Inserisci la distanza da percorrere: ");
    scanf("%lf", &distanza);

    printf("Inserisci il numero di spostamenti: ");
    scanf("%d", &num_spostamenti);

    double distanza_rimanente = distanza;  
    double distanza_coperta=0.0;

    for (int i = 0; i < num_spostamenti; i++) {
        distanza_rimanente = distanza_rimanente/ 2; 
        distanza_coperta = distanza_coperta +distanza_rimanente;
    }

    printf("Distanza effettivamente coperta dopo %d spostamenti: %lf \n", num_spostamenti, distanza_coperta);

    return 0;
}
