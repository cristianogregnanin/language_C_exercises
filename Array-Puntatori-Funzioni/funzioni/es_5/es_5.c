/**
 * @brief La ditta coders.io sta realizzando un modulo software per la gestione di un
 * magazzino composto da massimo 100 prodotti. Si vuole progettare e implementare
 * una funzionalità atta a tenere traccia dei prodotti presenti, in particolare
 * si scriva un programma in linguaggio C che chieda in input una serie di codici
 * di prodotti (uno per volta) e li inserisca in una lista, per terminare
 * l’inserimento si utilizzi il codice -1. 
 * Al termine dell’inserimento si vuole poter eliminare un prodotto
 * preventivamente ricercato e quindi stampare la lista a video.
 * Se il prodotto ricercato non esiste stampare a video un messaggio di errore.
 *
 * Esempio di utilizzo:
 * $ ./es.out                                                             
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 20
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 30
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 40
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 50
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * -1
 * Inserisci il codice del prodotto che vuoi eliminare: 
 * 40
 * prodotto: 20
 * prodotto: 30
 * prodotto: 50
 *
 * Esempio di utilizzo:
 * $ ./es.out                                                             
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 20
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 30
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 40
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * 50
 * Inserisci il codice del prodotto: (digita -1 per terminare)
 * -1
 * Inserisci il codice del prodotto che vuoi eliminare: 
 * 100
 * Prodotto non esistente 
 * 
 * @param argc elementi inseriti da riga di comando
 * @param argv insieme degli elementi inseriti da riga di comando
 * @param prodotti insieme dei prodotti nel magazzino
 * @param n contatore 
 * @param codice numero identificativo del prodotto
 * @param posizione indica la posizione del prodotto all'interno del magazzino
 * 
 * 
 * @return la funzione restituisce 0
 */

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