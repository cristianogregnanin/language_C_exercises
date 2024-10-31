/**
 * @brief Una terna pitagorica è un insieme di 3 numeri naturali a < b < c tali che a^2 + b^2 = c^2.
 *        Progettare un algoritmo che, a partire dai valori di tre numeri naturali, determini se essi
 *        costituiscono o meno una terna pitagorica.
 *
 * @param argc Numero di argomenti passati attraverso la riga di comando
 * @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
 * @return La funzione restituisce sempre 0.
 *
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;

    printf("Inserisci tre numeri naturali separati da spazi: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if (b > c)
    {
        b = b + c;
        c = b - c;
        b = b - c;
    }
    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    if (a * a + b * b == c * c)
    {
        printf("I numeri %d, %d e %d formano una terna pitagorica.\n", a, b, c);
    }
    else
    {
        printf("I numeri %d, %d e %d NON formano una terna pitagorica.\n", a, b, c);
    }
    return 0;
}
