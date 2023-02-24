#include <stdio.h>

int ricerca(int prodotti[], int n, int codice)
{

    for (int k = 0; k < n; k++)
    {

        if (prodotti[k] == codice)
        {
            return k;
        }
    }
    return -1;
}

int popola(int prodotti[])
{
    int codice, n = 0;
    while (1)
    {
        printf("Inserisci il codice del prodotto: (digita -1 per terminare)\n");
        scanf("%d", &codice);

        if (codice == -1)
        {
            return n;
        }
        prodotti[n] = codice;
        n++;
    }
}

int elimina(int prodotti[], int *n, int posizione)
{

    for (int i = posizione; i < *n; i++)
    {
        prodotti[i] = prodotti[i + 1];
    }
    (*n)--;
    return posizione;
}

void stampa(int prodotti[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("prodotto: %d\n", prodotti[i]);
    }
}

int main(int argc, char *argv[])
{

    int codice, posizione, prodotti[100], n = popola(prodotti);

    printf("Inserisci il codice del prodotto che vuoi eliminare: \n");
    scanf("%d", &codice);
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
