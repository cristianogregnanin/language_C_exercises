#include <stdio.h>
#include <string.h>
#define DIM_CODICE 5

typedef struct
{
    char codice[DIM_CODICE];
    double prezzo;
    int quantita;
} prodotto_t;

int ricerca(prodotto_t prodotti[], int n, char codice[DIM_CODICE])
{

    for (int k = 0; k < n; k++)
    {

        if (strcmp(prodotti[k].codice, codice) == 0)
        {
            return k;
        }
    }
    return -1;
}

int popola(prodotto_t prodotti[])
{
    char codice[DIM_CODICE];
    prodotto_t prodotto;
    int n = 0;

    while (1)
    {
        printf("Inserisci il codice del prodotto: (digita -1 per terminare)\n");
        scanf("%s", prodotto.codice);

        if (strcmp(prodotto.codice, "-1") == 0)
        {
            return n;
        }

        printf("Inserisci il prezzo:\n");
        scanf("%lf", &prodotto.prezzo);
        printf("Inserisci la quantita: \n");
        scanf("%d", &prodotto.quantita);
        prodotti[n] = prodotto;
        n++;
    }
}

int elimina(prodotto_t prodotti[], int *n, int posizione)
{

    for (int i = posizione; i < *n; i++)
    {
        prodotti[i] = prodotti[i + 1];
    }
    (*n)--;
    return posizione;
}

void stampa(prodotto_t prodotti[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("codice: %s\n", prodotti[i].codice);
        printf("prezzo: %.2f\n", prodotti[i].prezzo);
        printf("quantita: %d\n", prodotti[i].quantita);
    }
}

int main(int argc, char *argv[])
{

    prodotto_t prodotti[100];
    int posizione, n = popola(prodotti);
    char codice[DIM_CODICE];

    printf("Inserisci il codice del prodotto che vuoi eliminare: \n");
    scanf("%s", codice);
    posizione = ricerca(prodotti, n, codice);

    if (posizione >= 0)
    {
        elimina(prodotti, &n, posizione);
        stampa(prodotti, n);
    }
    else
    {
        printf("Prodotto non esistente\n");
    }

    return 0;
}
