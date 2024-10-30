/**
* @brief Un'onda marina anomala dimezza la propria altezza ogni km percorso e scompare raggiungendo un'altezza pari a zero quando l'altezza scende al di sotto del metro.
*       - Progettare un algoritmo che calcoli, a partire dai valori dell'altezza iniziale h e dal numero di km percorsi k, l'altezza raggiunta dall'onda.
*       - Modificare l'algoritmo precedente in modo che, a partire dalla sola altezza iniziale dell'onda h, determini il numero di km necessario prima che essa scompaia.
* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* @param argc Numero di argomenti passati attraverso la riga di comando
* 
* @return La funzione restituisce 0
*/

#include <stdio.h>

int main() {
    float altezzaIniziale;
    int kmPercorsi;
    
    printf("Inserisci l'altezza iniziale dell'onda: ");
    scanf("%f", &altezzaIniziale);
    
    printf("Inserisci il numero di km percorsi: ");
    scanf("%d", &kmPercorsi);
    
    float altezzaCorrente = altezzaIniziale;
    for(int i = 0; i < kmPercorsi; i++) {
        altezzaCorrente = altezzaCorrente / 2;
    }
    
    if(altezzaCorrente < 1) {
        altezzaCorrente = 0;
    }
    printf("Dopo %d km l'onda è alta %.2f metri\n", kmPercorsi, altezzaCorrente);
    
    altezzaCorrente = altezzaIniziale;
    int kmFinali = 0;
    while(altezzaCorrente >= 1) {
        altezzaCorrente = altezzaCorrente / 2;
        kmFinali++;
    }
    
    printf("L'onda scompare dopo %d km\n", kmFinali);
    
    return 0;
}