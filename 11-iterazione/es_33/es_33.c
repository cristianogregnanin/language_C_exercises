#include <stdio.h>

/**
 * @brief Un numero naturale N definito perfetto se è la somma di tutti i suoi divisori compresa l'unità (per esempio 6 è perfetto perché
 * è la somma dei suoi tre divisori(1, 2 e 3). Progettare un algoritmo che, a partire da un numero naturale N, determini se esso è perfetto o meno.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 * 
 * @return La funzione ritorna sempre 0.
 */
int main(int argc, char *argv[])
{

    int N;
    printf("Inserisci un numero naturale: ");
    scanf("%d", &N);

    int somma = 0;
    for (int i = 1; i <= N / 2; i++)
    {
        if (N % i == 0)
        {
            somma += i;
        }
    }
    if (somma == N)
    {
        printf("%d è un numero perfetto.\n", N);
    }
    else
    {
        printf("%d non è un numero perfetto.\n", N);
    }

    return 0;
}