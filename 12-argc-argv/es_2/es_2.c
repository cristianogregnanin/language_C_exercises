#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Si scriva un programma che calcoli l’elevazione a potenza del valore intero
 * passato come primo argomento per il secondo argomento intero.
 * 
 * Esempio:
 * 
 * $./es 2 3
 * 
 * output: 2 ^ 3 = 8
 * 
 * @param argc Il numero di argomenti da riga di comando.
 * Deve essere uguale a 3 per contenere nome del file, base ed esponente della potenza.
 * @param argv Array di stringhe contenente gli argomenti da riga di comando. 
 * @return La funzione ritorna sempre 0
*/
int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Errore argomenti\n");
        exit(0);
    }

    int base = atoi(argv[1]);
    int esponente = atoi(argv[2]);
    int risultato = 1;

    if (base < 0 || esponente < 0)
    {
        printf("Inserire numeri positivi\n");
        exit(0);
    }

    if (base == 0)
    {
        if (esponente == 0)
        {
            printf("Non puoi elevare 0 per se stesso\n");
            exit(0);
        }
        risultato = 0;
    }

    for (int i = 0; i < esponente; i++)
    {
        risultato = base * risultato;
    }

    printf("Il risultato di %d ^ %d è: %d\n", base, esponente, risultato);
    return 0;
}