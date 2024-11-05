#include <stdio.h>
#include <string.h>

int calcolo_lunghezza(char stringa[])
{
    return strlen(stringa);
}

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

int conteggio_vocali(int argc, char *argv[])
{
    int somma = 0;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + ricerca_vocali_in_stringa(argv[i]);
    }
    return somma;
}

int cerca_carattere(int argc, char *argv[], char carattere)
{

    int somma = 0;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + ricerca_carattere(argv[i], carattere);
    }
    return somma;
}

void conteggio_doppie(int argc, char *argv[], int *doppie, int *quantita_doppie)
{
}

int conteggio_palindrome(int argc, char *argv[])
{
    int palindrome = 0;

    return palindrome;
}

int main(int argc, char *argv[])
{
    char carattere;

    int lunghezza = calcolo_lunghezza(argv[1]);
    printf("La lunghezza è: %d\n", lunghezza);

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