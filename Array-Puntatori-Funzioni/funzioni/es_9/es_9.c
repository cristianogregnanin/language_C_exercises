#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Funzione che conta il numero di consonanti in una stringa
 *
 * @param stringa stringa in cui si cercano le consonanti
 *
 * @return Il numero di consonanti presenti nella stringa
 */
int ricerca_consonanti_in_stringa(char stringa[])
{
    char carattere;
    int numero_consonanti = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        carattere = stringa[i];
        if (carattere != 'a' && carattere != 'i' && carattere != 'o' && carattere != 'u' && carattere != 'e')
        {
            numero_consonanti++;
        }
    }
    return numero_consonanti;
}

/**
 * @brief Funzione che conta il numero di vocali in una stringa
 *
 * @param stringa stringa in cui si cercano le vocali
 *
 * @return Il numero di vocali presenti nella stringa
 */
int ricerca_vocali_in_stringa(char stringa[])
{
    char carattere;
    int numero_vocali = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        carattere = stringa[i];
        if (carattere == 'a' || carattere == 'i' || carattere == 'o' || carattere == 'u' || carattere == 'e')
        {
            numero_vocali++;
        }
    }
    return numero_vocali;
}

/**
 * @brief Funzione che conta quante volte un carattere specificato appare in una stringa.
 *
 * @param stringa L'array di caratteri in cui cercare il carattere
 * @param carattere Il carattere da cercare
 *
 * @return Il numero totale di occorrenze del carattere in tutte le stringhe
 */
int ricerca_carattere(char stringa[], char carattere)
{
    int contatore = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            contatore++;
        }
    }

    return contatore;
}

/**
 * @brief Funzione che somma il numero di vocali in ciascun argomento passato nella
 * riga di comando
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando
 *
 * @return La somma totale delle vocali tra tutti gli argomenti
 */
int conteggio_vocali(int argc, char *argv[])
{
    int somma_vocali = 0;
    for (int i = 1; i < argc; i++)
    {
        somma_vocali = somma_vocali + ricerca_vocali_in_stringa(argv[i]);
    }
    return somma_vocali;
}

/**
 * @brief Funzione che somma il numero di consonanti in ciascun argomento passato nella
 * riga di comando
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando
 *
 * @return La somma totale delle consonanti tra tutti gli argomenti
 */
int conteggio_consonanti(int argc, char *argv[])
{
    int somma_consonanti = 0;
    for (int i = 1; i < argc; i++)
    {
        somma_consonanti = somma_consonanti + ricerca_consonanti_in_stringa(argv[i]);
    }
    return somma_consonanti;
}

/**
 * @brief Funzione che conta quante volte un carattere specificato appare in ciascun
 * argomento della riga di comando.
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando
 * @param carattere Il carattere da cercare
 *
 * @return Il numero totale di occorrenze del carattere in tutte le stringhe
 */
int cerca_carattere(int argc, char *argv[], char carattere)
{

    int somma = 0;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + ricerca_carattere(argv[i], carattere);
    }

    return somma;
}

/**
 * @brief Conta il numero di lettere doppie presenti in ogni parola degli argomenti passati da riga di comando
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando, contenente anche la stringa e il carattere da contare
 * @param doppie Puntatore alla variabile in cui memorizzare il numero totale di doppie
 * @param quantita_doppie Puntatore alla variabile in cui memorizzare il numero di parole contenenti almeno una doppia
 */
void conteggio_doppie(int argc, char *argv[], int *doppie, int *quantita_doppie)
{
    *doppie = 0;
    *quantita_doppie = 0;

    for (int j = 0; j < argc; j++)
    {
        int doppie_parola_corrente = 0;

        for (int i = 0; i < strlen(argv[j]); i++)
        {
            /* Se un carattere precedente esiste ed
             * il carattere corrente e' uguale ad esso,
             * una doppia e' stata trovata.
             */
            if (i > 0 && argv[j][i] == argv[j][i - 1])
            {
                (*doppie)++;
                doppie_parola_corrente++;
            }
        }

        if (doppie_parola_corrente > 0)
        {
            (*quantita_doppie)++;
        }
    }
}

/**
 * @brief Controlla se la stringa passata e' palindroma o meno
 *
 * @param stringa la stringa da controllare
 *
 * @return 1 se la stringa e' palindroma, 0 se non lo e'
 */
int palindroma(char stringa[])
{
    int lunghezza = strlen(stringa);

    for (int i = 0; i < lunghezza; i++)
    {
        /*Se viene trovato un carattere della
         * stringa non invertibile la stringa
         * non e' palindroma.
         */
        if (stringa[i] != stringa[lunghezza - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Conta il numero di parole palindrome
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando, contenente anche la stringa e il carattere da contare
 *
 * @return la funzione ritorna il numero di parole palindrome
 */
int conteggio_palindrome(int argc, char *argv[])
{
    int palindrome = 0;

    for (int i = 0; i < argc; i++)
    {
        palindrome += palindroma(argv[i]);
    }

    return palindrome;
}

/**
 * @brief Funzione principale del programma
 *
 * @param argc numero di argomenti passati da riga di comando
 * @param argv array di stringhe contenente gli argomenti passati da riga di comando, contenente anche la stringa e il carattere da contare
 *
 * @return la funzione ritorna sempre 0
 */
int main(int argc, char *argv[])
{
    if(argc < 2) {
        exit(0);
    }

    char carattere;

    int lunghezza = strlen(argv[1]);
    printf("La lunghezza della prima parola è: %d\n", lunghezza);

    int consonanti = conteggio_consonanti(argc, argv);
    printf("il numero delle consonanti è: %d\n", consonanti);

    int vocali = conteggio_vocali(argc, argv);
    printf("il numero delle vocali è: %d\n", vocali);

    int doppie, quantita_doppie;
    conteggio_doppie(argc, argv, &doppie, &quantita_doppie);
    printf("In tutta la frase ci sono %d doppie\n", doppie);
    printf("In tutta la frase ci %d parole che contengono almeno una doppia\n", quantita_doppie);

    int numero_palindrome = conteggio_palindrome(argc, argv);
    printf("In tutta la frase ci sono %d parole palindrome\n", numero_palindrome);

    printf("Inserisci un carattere da ricercare: ");
    scanf("%c", &carattere);
    int ricerca = cerca_carattere(argc, argv, carattere);

    if (ricerca == 0)
    {
        printf("Il carattere non compare\n");
    }
    else
    {
        printf("Il carattere compare %d volte nella frase\n", ricerca);
    }

    return 0;
}