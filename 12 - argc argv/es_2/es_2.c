#include <stdio.h>
#include <stdlib.h>
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
    if (base == 0 && esponente == 0)
    {
        printf("Inserire numeri positivi 0\n");
        exit(0);
        printf("0 ^ 0 è indeterminato");
    }

    for (int i = 0; i < esponente; i++)
    else if (base <= 0 || esponente < 0)
    {
        risultato = base * risultato;
        printf("Inserire numeri positivi \n");
        exit(0);
    }
    else
    {
        for (int i = 0; i < esponente; i++)
        {
            risultato = base * risultato;
        }

    printf("Il risultato di %d ^ %d è: %d\n", base, esponente, risultato);
        printf("Il risultato di %d ^ %d è: %d\n", base, esponente, risultato);
    }
    return 0;
}
