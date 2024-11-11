#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Scrivi un programma che legge da argv[1] un numero intero positivo (N) e poi
 * disegna a terminale un quadrato vuoto composto di asterischi (‘*’)
 * con il lato lungo N:
 *
 * @verbatim
 * Per N pari a 3 il programma stampa:
 *
 * ***
 * * *
 * ***
 * 
 * Per N pari a 5 il programma stampa:
 *
 * *****
 * *   *
 * *   *
 * *   *
 * *****
 * @endverbatim
 *
 * @param argc argc numero di argomenti passati da riga di comando
 * @param argv argv argomenti passati da riga di comando
 *
 * @return ritorna 0 se il programma è corretto
 */

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Errore argomenti\n");
        exit(0);
    }

    int n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("argv[1] deve essere maggiore di 0\n");
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) 
            {
                printf(" *");
            }
            else 
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
