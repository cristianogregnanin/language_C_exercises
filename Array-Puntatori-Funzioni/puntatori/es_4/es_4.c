#include <stdio.h>
#include <limits.h>

/**
 * @brief Popola un array con numeri inseriti dall'utente.
 *
 * Il programma chiede all'utente di inserire dei valori interi. L'inserimento termina quando l'utente
 * inserisce il valore -1.
 *
 * @param numeri Array in cui vengono inseriti i numeri.
 * 
 * @return Il numero di elementi effettivamente inseriti nell'array.
 */
int popola(int numeri[])
{
    int valore = 0, n = 0;
    while (1)
    {
        printf("inserisci un valore. Premi -1 per terminare l'inserimento\n");
        scanf("%d", &valore);
        if (valore == -1)
        {
            return n;
        }

        numeri[n] = valore;
        n++;
    }
}

/**
 * @brief Stampa i valori di un array.
 * 
 * La funzione stampa tutti i valori presenti nell'array in ordine crescente.
 *
 * @param array Array di interi da stampare.
 * @param n Numero di elementi validi nell'array.
 */
void stampa(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Il valore in posizione %d è: %d\n", i, array[i]);
    }
}

/**
 * @brief Stampa i valori di un array in ordine inverso.
 * 
 * La funzione stampa tutti i valori presenti nell'array in ordine inverso, partendo dall'ultimo elemento.
 * 
 * @param array Array di interi da stampare.
 * @param n Numero di elementi validi nell'array.
 */
void stampa_inversa(int array[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("Il valore in posizione %d è: %d\n", i, array[i]);
    }
}

/**
 * @brief Trova il massimo valore in un array.
 * 
 * La funzione esamina tutti gli elementi dell'array e restituisce il valore massimo.
 *
 * @param array Array di interi da esaminare.
 * @param n Numero di elementi validi nell'array.
 * 
 * @return Il valore massimo nell'array.
 */
int massimo(int array[], int n)
{
    int massimo = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > massimo)
        {
            massimo = array[i];
        }
    }

    return massimo;
}

/**
 * @brief Ricerca un valore nell'array.
 * 
 * La funzione cerca un valore nell'array e restituisce la sua posizione se trovato, altrimenti restituisce -1.
 *
 * @param array Array in cui eseguire la ricerca.
 * @param n Numero di elementi validi nell'array.
 * @param valore Valore da cercare.
 * 
 * @return La posizione dell'elemento se trovato, -1 se non trovato.
 */
int ricerca(int array[], int n, int valore)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == valore)
        {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Inserisce un valore in una posizione specifica dell'array.
 * 
 *La funzione sposta gli elementi a partire dalla posizione in avanti, per fare spazio al nuovo valore.
 *
 * @param array Array in cui inserire il valore.
 * @param n Puntatore al numero di elementi validi nell'array.
 * @param posizione Posizione in cui inserire il nuovo valore.
 * @param valore Il valore da inserire.
 * 
 * @return La posizione in cui è stato inserito il valore.
 */
int inserisci_in_posizione(int array[], int *n, int posizione, int valore)
{
    for (int i = *n; i > posizione; i--)
    {
        array[i] = array[i - 1];
    }
    array[posizione] = valore;
    (*n)++;
    return posizione;
}

/**
 * @brief Inserisce un valore alla fine dell'array.
 * 
 * La funzione aggiunge un nuovo valore alla fine dell'array e incrementa la lunghezza dell'array.
 *
 * @param array Array in cui inserire il valore.
 * @param n Puntatore al numero di elementi validi nell'array.
 * @param numero Il numero da inserire.
 * 
 * @return La nuova dimensione dell'array.
 */
int inserisci_in_coda(int array[], int *n, int numero)
{
    array[*n] = numero;
    (*n)++;
    return *n;
}

/**
 * @brief Modifica un valore nell'array in una posizione specifica.
 * 
 * La funzione sostituisce il valore nell'array alla posizione specificata.
 *
 * @param array Array in cui modificare il valore.
 * @param posizione Posizione in cui modificare il valore.
 * @param valore Il nuovo valore da inserire.
 * 
 * @return La posizione in cui è stato modificato il valore.
 */
int modifica(int array[], int posizione, int valore)
{
    array[posizione] = valore;
    return posizione;
}

/**
 * @brief Elimina un valore nell'array.
 *
 * La funzione rimuove un elemento dall'array e sposta tutti gli elementi successivi per colmare il vuoto.
 *
 * @param array Array da cui eliminare il valore.
 * @param n Puntatore al numero di elementi validi nell'array.
 * @param posizione Posizione dell'elemento da eliminare.
 * 
 * @return La posizione dell'elemento eliminato.
 */
int elimina(int array[], int *n, int posizione)
{
    for (int i = posizione; i < *n - 1; i++)
    {
        array[i] = array[i + 1];
    }
    (*n)--;
    return posizione;
}

/**
 * @brief Esegue l'operazione selezionata dal menu.
 *
 * In base alla scelta dell'utente, esegue una delle operazioni sugli array.
 *
 * @param s La scelta dell'utente.
 * @param numeri L'array di numeri su cui eseguire l'operazione.
 * @param n Puntatore al numero di elementi validi nell'array.
 */
void esegui_operazione(int s, int numeri[], int *n)
{
    if (s == 1)
    {
        stampa(numeri, *n);
    }
    if (s == 2)
    {
        int numero, posizione;
        printf("inserisci un numero: ");
        scanf("%d", &numero);
        posizione = inserisci_in_coda(numeri, n, numero);
        printf("Valore inserito in posizione: %d", posizione);
    }
    if (s == 3)
    {
        int valore, posizione;
        printf("Inserisci il valore da sostituire: ");
        scanf("%d", &valore);
        posizione = ricerca(numeri, *n, valore);

        if (posizione > -1)
        {
            printf("Inserisci il nuovo valore: ");
            scanf("%d", &valore);
            modifica(numeri, posizione, valore);
        }
        else
        {
            printf("valore non esistente");
        }
    }
    if (s == 4)
    {
        int valore, posizione;
        printf("Inserisci il valore da eliminare: ");
        scanf("%d", &valore);
        posizione = ricerca(numeri, *n, valore);

        if (posizione > -1)
        {
            elimina(numeri, n, posizione);
        }
        else
        {
            printf("valore non esistente");
        }
    }
    if (s == 5)
    {
        int posizione, valore;
        printf("Inserisci il valore da ricercare: ");
        scanf("%d", &valore);
        posizione = ricerca(numeri, *n, valore);

        if (posizione > -1)
        {
            printf("valore trovato in posizione %d", posizione);
        }
        else
        {
            printf("valore non esistente");
        }
    }

    if (s == 6)
    {
        int valore, posizione;
        printf("Inserisci il valore da aggiungere: ");
        scanf("%d", &valore);
        printf("Inserisci la posizione: ");
        scanf("%d", &posizione);

        if (posizione < *n)
        {
            inserisci_in_posizione(numeri, n, posizione, valore);
        }
        else
        {
            printf("valore non esistente");
        }
    }
    if (s == 7)
    {
        stampa_inversa(numeri, *n);
    }

    if (s == 8)
    {
        int max = massimo(numeri, *n);
        printf("Il massimo dell'array è: %d", max);
    }
}

/**
 * @brief Mostra il menu delle operazioni disponibili.
 *
 * Mostra un menu interattivo che consente all'utente di scegliere un'operazione da eseguire.
 *
 * @return La scelta dell'utente.
 */
int menu()
{
    int scelta;

    printf("\n\npremere 1 per mostrare il contenuto dell'array\n");
    printf("premere 2 per inserire un elemento in coda\n");
    printf("premere 3 per modificare un elemento\n");
    printf("premere 4 per eliminare un elemento\n");
    printf("premere 5 per ricercare un elemento\n");
    printf("premere 6 per inserire un elemento in una certa posizione\n");
    printf("premere 7 per mostrare il contenuto dell'array all'inverso\n");
    printf("premere 8 per mostrare il valore massimo dell'array\n");
    printf("premere 0 per terminare\n");

    scanf("%d", &scelta);

    return scelta;
}

/**
 * @brief Dato un array di dimensione massima pari a SHRT_MAX,
 * inserire in input un numero arbitrario di interi positivi.
 * L'inserimento termina quando viene inserito il valore -1.
 * 
 * Si mostri quindi un menu cosi strutturato:
 * premere 1 per mostrare il contenuto dell'array
 * premere 2 per inserire un elemento in coda
 * premere 3 per modificare un elemento, se presente
 * premere 4 per eliminare un elemento, se presente
 * premere 5 per ricercare un elemento
 * premere 6 per inserire un elemento in una certa posizione
 * premere 7 per mostrare il contenuto dell'array all'invers
 * premere 8 per mostrare il valore massimo dell'array
 * premere 0 per terminare
 * 
 * dopo ogni operazione il menu deve essere nuovamente mostrato
 * 
 * osservazione
 * SHRT_MAX è dichiarata in limits.
 * 
 * Vincolo:
 * è obbligatorio strutturare il programma in funzioni
 *
 * @param argc Numero di argomenti passati al programma.
 * @param argv Array di stringhe contenenti gli argomenti passati al programma.
 * 
 * @return 0 se il programma termina correttamente.
 */
int main(int argc, char *argv[])
{
    int scelta, numeri[SHRT_MAX], n = popola(numeri);

    while (1)
    {
        scelta = menu();

        if (scelta == 0)
        {
            printf("\tprogramma terminato\n");
            return 0;
        }
        esegui_operazione(scelta, numeri, &n);
    }

    return 0;
}
