#include <stdio.h>
#include <stdlib.h>

/**
*
* @brief Funzione principale del programma.
*
* Questa funzione legge un numero `n` di valori interi in ordine crescente,
* verifica se la sequenza è una progressione aritmetica, e calcola la differenza
* massima tra gli elementi consecutivi se non è una progressione.
*
* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* @param argc Numero di argomenti passati attraverso la riga di comando
*
* @return 0 se il programma termina correttamente, 1 se ci sono errori.
*
*/

int main(int argv,char *argc) {
    int n;
   

    do{
         printf("Inserisci il numero di elementi: ");
         scanf("%d", &n);

        printf("Servono almeno 2 valori.\n");
    }while(n<2);

    

    int arr[n];
    printf("Inserisci gli elementi in ordine crescente:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int diff = arr[1] - arr[0];  // Differenza iniziale
    int arimetico = 1;       // Serve per controllare se è una progressione aritmetica
    int max_diff = diff;         // Variabile per la differenza massima

    for (int i = 2; i < n; i++) {
        int diff2 = arr[i] - arr[i - 1];
        if (diff2 != diff) {
            arimetico = 0; // Non è una progressione aritmetica
        }
        if (diff2 > max_diff) {
            max_diff = diff2; // Aggiorna la differenza massima
        }
    }

    if (arimetico) {
        printf("I numeri sono in progressione aritmetica con differenza: %d\n", diff);
    } else {
        printf("I numeri non sono in progressione aritmetica. Differenza massima: %d\n", max_diff);
    }

    return 0;
}
