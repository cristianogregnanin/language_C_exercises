/**
 * @brief L'accrescimento della popolazione umana e' guidato da una semplice legge matematica:
 * l'incremento della popolazione tra un anno e il successivo e' dato dal prodotto di una costante
 * (il tasso di accrescimento) per la dimensione della popolazione.
 * Realizzare l'algoritmo che consenta di simulare anno per anno i valori della dimensione della popolazione a partire:
 * - dall'anno iniziale della simulazione;
 * - dal valore della dimensione iniziale della popolazione;
 * - dal valore del tasso di accrescimento;
 * - dall'anno finale della simulazione.
 *
 * @param argc Numero di argomenti passati attraverso la riga di comando
 * @param argv argomenti passati attraverso la riga di comando
 *
 * @return La funzione restituisce 0
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    int anno_iniziale, anno_finale;
    double popolazione_iniziale, popolazione_attuale, tasso_accrescimento;

    printf("PROGRAMMA ACCRESCIMENTO POPOLAZIONE UMANA\n");

    // inserimento anno iniziale simulazione
    do
    {
        printf("\nInserisci l'anno d'inzio simulazione (deve essere >= 0): ");
        scanf("%d", &anno_iniziale);
    } while (anno_iniziale < 0);

    // inserimento anno finale simulazione
    do
    {
        printf("\nInserisci l'anno di fine simulazione (deve essere >= 0 e maggiore dell'anno iniziale): ");
        scanf("%d", &anno_finale);
    } while (anno_finale < 0 || anno_finale <= anno_iniziale);

    // inserimento dimensione popolazione iniziale
    do
    {
        printf("\nInserisci la dimensione iniziale della popolazione (deve essere >= 0): ");
        scanf("%lf", &popolazione_iniziale);
    } while (popolazione_iniziale < 0);

    // inserimento tasso di accrescimento della popolazione
    do
    {
        printf("\nInserisci il tasso di accrescimento (deve essere >= 0, es. 0.01 equivale a un incremento dell'1%%: ");
        scanf("%lf", &tasso_accrescimento);
    } while (tasso_accrescimento < 0);

    popolazione_attuale = popolazione_iniziale;

    // stampa risultato per anno e popolazione con crescita
    printf("\nAnno   Popolazione\n");

    for (int i = anno_iniziale; i <= anno_finale; i++)
    {
        printf("%d      %.2f\n", i, popolazione_attuale);
        popolazione_attuale += popolazione_attuale * tasso_accrescimento;
    }

    return 0;
}
