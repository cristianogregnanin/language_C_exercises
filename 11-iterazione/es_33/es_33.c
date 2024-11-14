#include <stdio.h>

/**
 * @brief Un numero naturale N e' definito perfetto se e' la somma di tutti i suoi divisori compresa l'unita' (per esempio 6 e' perfetto perche'
 * e' la somma dei suoi tre divisori(1, 2 e 3)). Progettare un algoritmo che, a partire da un numero naturale N, determini se esso e' perfetto o meno.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da riga di comando.
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
            somma = somma + i;
        }
    }
    if (somma == N)
    {
        printf("%d e' un numero perfetto.\n", N);
    }
    else
    {
        printf("%d non e' un numero perfetto.\n", N);
    }
    
    return 0;
}
