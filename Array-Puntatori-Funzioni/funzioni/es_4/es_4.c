#include <stdio.h>
#include <string.h>

/**
 * @brief Ricerca le vocali minuscole di una stringa
 * 
 * @param stringa è la stringa che passiamo alla funzione
 * 
 * @return restituisce il numero di vocali trovate
 *
*/

int ricerca_vocali(char stringa[])
{

    int vocali = 0;

    for (int k = 0; k < strlen(stringa); k++)
    {

        if (stringa[k] == 'a' || stringa[k] == 'i' || stringa[k] == 'u' || stringa[k] == 'o' || stringa[k] == 'e')
        {
            vocali++;
        }
    }
    return vocali;
}

/**
 *  @brief Data una serie di stringhe lette da riga di comando scrivere un programma che
 *         conta quante sono le consonanti e conta quante sono le vocali.
 *         Al termine del programma si vuole visualizzare in output i due conteggi.
 *
 *         Osservazione:
 *         si strutturi il programma usando almeno una funzione
 *
 *         Nota:
 *         per semplicità si decide che un carattere può essere una vocale oppure una 
 *         consonante. 
 * 
 *  @param argc Numero di argomenti della riga di comando.
 *  @param argv Array di stringhe che contiene gli argomenti della riga di comando.
 *  
 *  @return ritorna 0 se il programma viene eseguito correttamente 
*/

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Numero argomenti sbagliato\n");
        return -1;
    }

    int vocali, consonanti, totvocali = 0, totconsonanti = 0;

    for (int i = 1; i < argc; i++)
    {
        vocali = ricerca_vocali(argv[i]);
        consonanti = strlen(argv[i]) - vocali;

        totvocali = totvocali + vocali;
        totconsonanti = totconsonanti + consonanti;
    }

    printf("vocali: %d, consonanti: %d\n", totvocali, totconsonanti);

    return 0;
}
