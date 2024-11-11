#include <stdio.h>


/**
 * @brief Progettare un algoritmo che effettui le seguenti operazioni:
 *  -continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
 *    0 (zero)
 *  - per ogni coppia di numeri letti:
 *      - calcoli il prodotto dei due numeri e ne stampi il valore
 *      - sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
 *  - all’uscita del ciclo, stampi il valore della somma
 * @param argc Numero di argomenti passati attraverso la riga di comando
 * @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
 *
 * @return La funzione restituisce 0
 */


int main(int argc, char *argv[])
{


    int a, b, prodotto, somma = 0;


    do
    {
        printf("inserisci a\n");
        scanf("%d", &a);
        printf("inserisci b\n");
        scanf("%d", &b);


        prodotto = a * b;
        printf("il prodotto è: %d\n\n", prodotto);


        somma = somma + prodotto;
       
    } while (a != 0 && b != 0);


    printf("la somma è: %d\n\n", somma);


    return 0;
}
