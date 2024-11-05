#include <stdio.h>

/**
 * @brief Ricerca un prodotto dato il codice
 *
 * @param prodotti Array di interi contenente i codici dei prodotti.
 * @param n Numero di prodotti attualmente nel magazzino.
 * @param codice Il codice del prodotto da ricercare.
 * @return La funzione restituisce la posizione (indice) del prodotto nell'array se trovato, altrimenti -1.
 */

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

/**
 * @brief Popola l'array con nuovi prodotti
 *
 * @param prodotti Array di interi in cui verranno inseriti i codici dei prodotti.
 *
 * @return La funzione restituisce il numero di prodotti.
 */

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


/**
 * @brief Ricerca un prodotto dato il codice.
 *
 * @param prodotti Array di interi contenente i codici dei prodotti.
 * @param n Numero di prodotti attualmente nel magazzino.
 * @param codice Il codice del prodotto da ricercare.
 * @return La funzione restituisce la posizione (indice) del prodotto nell'array se trovato, altrimenti -1.
 */
int ricerca(int prodotti[], int n, int codice)
{
    for (int k = 0; k < n; k++)
    {
        if (prodotti[k] == codice)
        {
            return k;
        }
    }
    return -1; // Se il prodotto non è trovato
}

/**
 * @brief Popola l'array con nuovi codici di prodotto inseriti dall'utente.
 *
 * @param prodotti Array di interi in cui verranno inseriti i codici dei prodotti.
 * @return Il numero di prodotti inseriti nell'array.
 */
int popola(int prodotti[])
{
    int codice, n = 0;
    while (1)
    {
        printf("Inserisci il codice del prodotto: (digita -1 per terminare)\n");
        scanf("%d", &codice);

        if (codice == -1)
        {
            return n; // Termina l'inserimento
        }
        prodotti[n] = codice;
        n++;
    }
}

/**
 * @brief Elimina un prodotto dato la sua posizione nell'array e riduce il numero di prodotti.
 *
 * @param prodotti Array di interi contenente i codici dei prodotti.
 * @param n Puntatore al numero di prodotti nell'array.
 * @param posizione La posizione del prodotto da eliminare nell'array.
 *
 * @return La funzione restituisce la posizione dei prodotti.
 */

int elimina(int prodotti[], int *n, int posizione)
{

    for (int i = posizione; i < *n; i++)
    {
        prodotti[i] = prodotti[i + 1];
    }
    (*n)--;
    return posizione;
}

/**
 * @brief Stampa i prodotti dell'array
 *
 * @param prodotti Array di interi contenente i codici dei prodotti.
 * @param n Numero di prodotti attualmente nel magazzino.
 *
 */

void stampa(int prodotti[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("prodotto: %d\n", prodotti[i]);
    }
}

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
 * @param argv Array di stringhe (array di caratteri) contenente gli argomenti da riga di comando
 * @param argc Numero di argomenti da riga di comando
 *
 * @return La funzione restituisce sempre 0.
 */

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
