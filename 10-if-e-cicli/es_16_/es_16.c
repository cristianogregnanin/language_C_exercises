/**
* @brief Progettare un algoritmo per calcolare il costo di un abbonamento alla metropolitana in base a:
*   • durata dell'abbonamento (settimanale, mensile o annuale)
*   • tipo di zona (centrale, periferica o entrambe)
*   • priorità (alta o bassa)
* 
*   L'utente fornisce i dati sopra elencati e il programma calcola il costo 
*   applicando uno sconto del 20% se la priorità è bassa.
* 
* @param argc Numero di argomenti passati attraverso la riga di comando
* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* 
* @return La funzione restituisce 0 al termine dell'esecuzione
*/


#include <stdio.h>

int main() {
    char durata, priorita;
    int tipo;
    double costo = 0.0;

    // Input dati dall'utente
    do {
        printf("Inserisci la durata dell'abbonamento (S per settimanale, M per mensile, A per annuale): ");
        scanf(" %c", &durata);
    } while (durata != 'S' && durata != 'M' && durata != 'A');

    do {
        printf("Inserisci il tipo di abbonamento (1 per zona centrale, 2 per zona periferica, 3 per entrambe le zone): ");
        scanf("%d", &tipo);
    } while (tipo < 1 || tipo > 3);

    do {
        printf("Inserisci la priorità (A per alta, B per bassa): ");
        scanf(" %c", &priorita);
    } while (priorita != 'A' && priorita != 'B');

    // Calcolo del costo in base al tipo e alla durata
    if (tipo == 1) {
        if (durata == 'S') costo = 10;
        else if (durata == 'M') costo = 30;
        else if (durata == 'A') costo = 250;
    } else if (tipo == 2) {
        if (durata == 'S') costo = 5;
        else if (durata == 'M') costo = 20;
        else if (durata == 'A') costo = 150;
    } else if (tipo == 3) {
        if (durata == 'S') costo = 15;
        else if (durata == 'M') costo = 40;
        else if (durata == 'A') costo = 300;
    }

    // Applica riduzione del 20% se priorità è bassa
    if (priorita == 'B') {
        costo *= 0.8;
    }

    // Stampa il costo finale
    printf("Il costo dell'abbonamento è: %.2f €\n", costo);

    return 0;
}

