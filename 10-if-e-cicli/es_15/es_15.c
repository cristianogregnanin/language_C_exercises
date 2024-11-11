#include <stdio.h>

/**
 * @brief Un professore assegna i livelli di valutazione (A,B,C,D,E) ai propri studenti in base alla seguente tabella dei punteggi:
 *        0 - 40 E
 *       41 - 60 D
 *       61 - 70 C
 *       71 - 85 B
 *       86 - 100 A
 * Progettare un algoritmo che consenta di determinare il livello di valutazione a partire dal punteggio.
 *
 * @param argc Numero di argomenti della riga di comando (non utilizzato).
 * @param argv Array di stringhe contenente gli argomenti (non utilizzato).
 *
 * @return ritorna zero.
 */

int main(int argc, char *argv[])
{
    int punteggio;
    char valutazione;

    printf("Inserisci il punteggio (0-100): ");
    scanf("%d", &punteggio);

    if (punteggio < 0 || punteggio > 100)
    {
        printf("Punteggio non valido. Inserire un valore tra 0 e 100.\n");
        return 1;
    }

    if (punteggio <= 40)
    {
        valutazione = 'E';
    }
    else if (punteggio <= 60)
    {
        valutazione = 'D';
    }
    else if (punteggio <= 70)
    {
        valutazione = 'C';
    }
    else if (punteggio <= 85)
    {
        valutazione = 'B';
    }
    else
    {
        valutazione = 'A';
    }

    printf("Livello di valutazione: %c\n", valutazione);

    return 0;
}
