

#include <stdio.h>
#include <string.h>

/**
 * @brief Calcola la lunghezza di una stringa.
 *
 * @param stringa stringa di cui calcolare la lunghezza.
 *
 * @return La lunghezza della stringa
 */
int calcolo_lunghezza(char stringa[])
{
    return strlen(stringa);
}

/**
 * @brief Ricerca le consonanti in una stringa.
 *
 * @param stringa stringa di cui calcolare il numero di consonanti.
 *
 * @return Il numero di consonanti della stringa.
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
 * @brief Ricerca le vocali in una stringa.
 *
 * @param stringa stringa di cui calcolare il numero di vocali.
 *
 * @return Il numero di vocali della stringa.
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
 * @brief Ricerca le vocali nell'intera frase.
 *
 * @param argc dimesione di argv.
 * @param argv array di stringhe.
 *
 * @return Il numero di vocali nella frase.
 */
int conteggio_vocali(int argc, char *argv[])
{
    int somma = 0;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + ricerca_vocali_in_stringa(argv[i]);
    }
    return somma;
}

/**
 * @brief Ricerca le consonanti nell'intera frase.
 *
 * @param argc dimesione di argv.
 * @param argv array di stringhe.
 *
 * @return Il numero di consonanti nella frase.
 */
int conteggio_consonanti(int argc, char *argv[])
{

    int somma = 0;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + ricerca_consonanti_in_stringa(argv[i]);
    }
    return somma;
}

/**
 * @brief Conteggio spazi bianchi nella frase.
 *
 * @param argc numero di stringhe nella frase.
 *
 * @return Il numero di spazi bianchi nella frase.
 */
int conteggio_spazi_bianchi(int argc)
{
    return argc - 2;
}

/**
 * @brief Ricerca quante volte compare un carattere in una stringa.
 *
 * @param stringa stringa in cui ricercare il carattere.
 * @param carattere carattere da ricercare.
 *
 * @return numero di volte che compare un carattere nella stringa.
 */
int ricerca_carattere(char stringa[], char carattere)
{

    int n = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            n++;
        }
    }
    return n++;
}

/**
 * @brief Ricerca quante volte compare un carattere in una frase.
 *
 * @param argc dimensione di argv[]
 * @param argv array di stringhe.
 * @param carattere carattere da ricercare.
 *
 * @return numero di volte che compare un carattere nella frase.
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
 * @brief Scrivi un programma in linguaggio C che riceva in input una frase da linea di comando e fornica il seguente output:
 * 1) Calcolo della lunghezza della prima parola della stringa.
 * 2) Conteggio del numero delle consonanti presenti in tutta la frase.
 * 3) Conteggio degli spazi bianchi e delle vocali presenti nella frase.
 * 4) Dato un carattere chiesto in input, dire quante volte compare nella frase.
 *
 * VINCOLI :
 * Il programma deve essere scritto in modo modulare, separando le diverse operazioni in funzioni distinte, ogni funzione deve avere uno scopo specifico.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 *
 * @return La funzione ritorna sempre 0.
 */

int main(int argc, char *argv[])
{
    char carattere;

    int lunghezza = calcolo_lunghezza(argv[1]);
    printf("La lunghezza è: %d\n", lunghezza);

    int consonanti = conteggio_consonanti(argc, argv);
    printf("il numero delle consonanti è: %d\n", consonanti);

    int spazi_bianchi = conteggio_spazi_bianchi(argc);
    int vocali = conteggio_vocali(argc, argv);
    int somma = spazi_bianchi + vocali;
    printf("il numero delle vocali e degli spazi bianchi è: %d\n", somma);

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
