#include <stdio.h>

/**
 * @brief Leggere in input da tastiera due numeri maggiori di 0 e farne la somma. 
 * 
 * @param valore Il valore da verificare.
 * @return int Il valore stesso se positivo, -1 altrimenti.
 */
int verifica_input(int valore)
{
    if (valore > 0)
        return valore;
    else
        return -1;
}

/**
 * @brief Calcola la somma di due numeri interi.
 * 
 * Questa funzione accetta due interi come argomenti e restituisce
 * la loro somma.
 * 
 * @param n1 Primo intero da sommare.
 * @param n2 Secondo intero da sommare.
 * @return int La somma di n1 e n2.
 */
int calcola_somma(int n1, int n2)
{
    return n1 + n2;
}

/**
 * @brief Funzione principale del programma.
 * 
 * Questa funzione chiede all'utente di inserire due numeri interi
 * positivi, li verifica utilizzando verifica_input() e calcola la loro
 * somma usando calcola_somma(). Il risultato viene poi stampato.
 * 
 * @param argc Numero di argomenti da riga di comando (non usato).
 * @param argv Argomenti da riga di comando (non usato).
 * @return int 0 se il programma termina correttamente.
 */
int main(int argc, char *argv[])
{
    int a, b, somma;

    do
    {
        printf("Inserisci a: ");
        scanf("%d", &a);
    } while (verifica_input(a) < 0);

    do
    {
        printf("Inserisci b: ");
        scanf("%d", &b);
    } while (verifica_input(b) < 0);

    somma = calcola_somma(a, b);

    printf("la somma è: %d\n", somma);

    return 0;
}
