/**
 * @brief La popolazione di un particolare batterio raddoppia ogni ora. 
 * Progettare un algoritmo che, a partire dal numero di ore trascorse e 
 * dal valore espresso in unită di carica batterica della consistenza iniziale 
 * della popolazione batterica, ne calcoli la consistenza finale raggiunta.
 * 
 * 
 * 
 * @param argc Numero di argomenti inseriti da riga di comando
 * @param argv Array di stringhe contenente gli argomenti inseriti da riga di comando
 * 
 * @return La funzione restituisce 0.
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int ore;
    double consistenza_iniziale;
    double consistenza_finale;

    printf("Inserisci il numero di ore trascorse: ");
    scanf("%d", &ore);

    printf("Inserisci la consistenza iniziale della popolazione batterica: ");
    scanf("%lf", &consistenza_iniziale);

    consistenza_finale = consistenza_iniziale * pow(2, ore);

    printf("La consistenza finale della popolazione batterica è: %.2lf\n", consistenza_finale);

    return 0;
}