/**
 * @brief II seguente algoritmo determina il giorno della settimana corrispondente a una data successiva al 15 ottobre 1582 ed espressa mediante tre valori numerici che rappresentano rispettivamente il giorno (G), il mese (M) e l'anno (A):
 * • il valore di M deve essere diminuito di 2;
 * • se il valore di M è negativo allora al valore di A deve essere sottratto 1 e al valore di M deve essere sommato 12;
 * • il giorno della settimana è dato dal resto della divisione per 7 del risultato della seguente somma algebrica:
 * - valore di G;
 * - valore di A;
 * - parte intera di A/4;
 * - parte intera di A/100 con segno negativo;
 * - parte intera di A/400;
 * - parte intera di (M-2) * 31/12.
 * Se il risultato è 0 il giorno è domenica, se è 1 lunedì, se è 2 martedì e così via fino a 6 che corrisponde a sabato.
 *
 * @param argc Numero di argomenti passati attraverso la riga di comando
 * @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{

    int G, M, A, somma = 0, giornoSettimana;

    do
    {
        printf("Inserisci il giorno\n");
        scanf("%d", &G);
        printf("Inserisci il mese\n");
        scanf("%d", &M);
        printf("Inserisci l'anno\n");
        scanf("%d", &A);
        if ((A < 1582) || (A == 1582 && M < 10) || (A == 1582 && M == 10 && G <= 15))
            printf("La data dev'essere successiva al 15 ottobre 1582\n");
    } while ((A < 1582) || (A == 1582 && M < 10) || (A == 1582 && M == 10 && G <= 15));

    M -= 2;
    if (M < 0)
    {
        A = A - 1;
        M = M + 12;
    }

    somma = G + A;
    somma = somma + (A / 4);
    somma = somma - (A / 100);
    somma = somma + (A / 400);
    somma = somma + ((M * 31) / 12);

    giornoSettimana = somma % 7;

    if (giornoSettimana == 0)
    {
        printf("Domenica\n");
    }
    else if (giornoSettimana == 1)
    {
        printf("Lunedi\n");
    }
    else if (giornoSettimana == 2)
    {
        printf("Martedi\n");
    }
    else if (giornoSettimana == 3)
    {
        printf("Mercoledi\n");
    }
    else if (giornoSettimana == 4)
    {
        printf("Giovedi\n");
    }
    else if (giornoSettimana == 5)
    {
        printf("Venerdi\n");
    }
    else if (giornoSettimana == 6)
    {
        printf("Sabato\n");
    }

    return 0;
}
