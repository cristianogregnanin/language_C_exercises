#include <stdio.h>
#include <string.h>

/**
 * @brief Esegue una somma tra due valori e incrementa il puntatore passato
 *
 * @param a Il primo addendo
 * @param b Il secondo addendo
 * @param totale Il puntatore il cui valore puntato viene incrementato
 *
 * @return La somma dei due valori
 */
double somma(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a + b;
}

/**
 * @brief Esegue una divisione tra due valori e incrementa il puntatore passato
 *
 * @param a Il dividendo
 * @param b Il divisore
 * @param totale Il puntatore il cui valore puntato viene incrementato
 *
 * @return Il rapporto dei due valori
 */
double divisione(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a / b;
}

/**
 * @brief Esegue una sottrazione tra due valori e incrementa il puntatore passato
 *
 * @param a Il primo operando
 * @param b Il secondo operando
 * @param totale Il puntatore il cui valore puntato viene incrementato
 *
 * @return La differenza tra i due valori
 */
double sottrazione(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a - b;
}

/**
 * @brief Esegue una moltiplicazione tra due valori e incrementa il puntatore passato
 *
 * @param a Il primo fattore
 * @param b Il secondo fattore
 * @param totale Il puntatore il cui valore puntato viene incrementato
 *
 * @return Il prodotto dei due valori
 */
double moltiplicazione(double a, double b, int *totale)
{
    *totale = *totale + 1;
    return a * b;
}

/**
 * @brief La ditta TechnoForce SRL deve progettare una calcolatrice che deve essere usata dagli operatori del
 * supermercato SuperLandia SPA.
 * La calcolatrice dovrà restare sempre accesa chiedendo in input ad ogni iterazione 2 numeri e un'operazione.
 * Quando l'operazione sarà pari a "fine" allora il software dovrà terminare mostrando a video il numero totale
 * delle richieste soddisfatte.
 *
 * Note operative:
 * 1) è obbligatorio progettare la calcolatrice usando almeno quattro funzioni
 *
 * 2) dopo ogni calcolo mostrare a video il risultato dell'operazione
 *
 * 3) Al termine il programma deve obbligatoriamente mostrare a video il numero totale
 * di operazioni richieste, usare obbligatoriamente i puntatori per implementare tale funzionalità
 *
 * 4) Le funzioni non devono contenere per nessun motivo istruzioni di output
 * come ad esempio "printf"
 *
 * 5) Le uniche printf devono comparire nel main
 *
 * 6) per il confronto fra stringhe usare la funzione strcmp
 *
 *
 * Esempio di utilizzo:
 * $ ./a.out
 * Inserisci a:
 * 10
 * Inserisci b:
 * 5
 * Inserisci l'operazione:
 * +
 * il risultato è:
 * 15
 *
 * Inserisci a:
 * 10
 * Inserisci b:
 * 5
 * Inserisci l'operazione:
 * -
 * il risultato è:
 * 5
 *
 * Inserisci a:
 * 10
 * Inserisci b:
 * 5
 * Inserisci l'operazione:
 * fine
 * Sono state eseguite 2 operazioni.
 *
 * @param argc Numero di argomenti da riga di comando
 * @param argv Array di stringhe contenenti gli argomenti da riga di comando
 *
 * @return La funzione ritorna sempre 0
 */
int main(int argc, char *argv[])
{
    double a, b, risultato;
    int totale = 0;
    char operazione[4];

    do
    {
        printf("inserisci a: ");
        scanf("%lf", &a);
        printf("inserisci b: ");
        scanf("%lf", &b);
        printf("inserisci operazione: ");
        scanf("%s", operazione);

        if (strcmp(operazione, "+") == 0)
        {
            risultato = somma(a, b, &totale);
        }
        if (strcmp(operazione, "/") == 0)
        {
            risultato = divisione(a, b, &totale);
        }
        if (strcmp(operazione, "*") == 0)
        {
            risultato = moltiplicazione(a, b, &totale);
        }
        if (strcmp(operazione, "-") == 0)
        {
            risultato = sottrazione(a, b, &totale);
        }

        if (strcmp(operazione, "fine") != 0)
        {
            printf("Il risultato é: %.2f\n", risultato);
        }
    } while (strcmp(operazione, "fine") != 0);

    printf("Sono state eseguite %d operazioni.\n", totale);

    return 0;
}