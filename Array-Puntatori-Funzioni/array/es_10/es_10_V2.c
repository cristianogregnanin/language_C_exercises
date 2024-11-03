/**
 * @brief Si scriva un programma che legga da riga di comando una stringa di 8 numeri
 *        che rappresenta la data di nascita di uno studente, si verifichi che gli 8 numeri
 *        siano coerenti con il formato di una data, quindi i primi 2 caratteri non devono
 *        essere maggiori di 31, la seconda coppia di caratteri non deve essere maggiore da 12
 *        e i restanti 4 caratteri non devono essere maggiori dell'anno corrente.
 *        Si stampi a video la data nel seguente formato: %d/%m/%Y
 *
 * @param argc Numero di argomenti passati da riga di comando.
 * @param argv Array di stringhe contenente gli argomenti da riga di comando.
 *
 * @return 0 Se il programma è eseguito con successo.
 * @return -1 In caso di errore.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_ANNO 4
#define DIM_GIORNO 2
#define DIM_MESE 2

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilizzo: Inserire una stringa di 8 caratteri \n");
        return -1;
    }

    if (strlen(argv[1]) != 8)
    {
        printf("La lunghezza della stringa è errata, la lunghezza deve essere di 8 caratteri\n");
        return -1;
    }

    char str_giorno[DIM_GIORNO], str_mese[DIM_MESE], str_anno[DIM_ANNO];
    int i, giorno, mese, anno, k = 0;

    str_giorno[0] = argv[1][0];
    str_giorno[1] = argv[1][1];
    giorno = atoi(str_giorno);

    if (giorno > 31 || giorno < 1)
    {
        printf("Data invalida \n");
        return -1;
    }

    str_mese[0] = argv[1][2];
    str_mese[1] = argv[1][3];

    mese = atoi(str_mese);
    if (mese > 12 || mese < 1)
    {
        printf("Data invalida \n");
        return -1;
    }

    str_anno[0] = argv[1][4];
    str_anno[1] = argv[1][5];
    str_anno[2] = argv[1][6];
    str_anno[3] = argv[1][7];

    anno = atoi(str_anno);
    if (anno > 2022 || anno < 1)
    {
        printf("Data invalida \n");
        return -1;
    }

    if (giorno < 10 && mese < 10)
    {
        printf("0%d/0%d/%d \n", giorno, mese, anno);
    }
    else if (giorno < 10)
    {
        printf("0%d/%d/%d \n", giorno, mese, anno);
    }
    else if (mese < 10)
    {
        printf("%d/0%d/%d \n", giorno, mese, anno);
    }
    else
    {
        printf("%d/%d/%d \n", giorno, mese, anno);
    }

    return 0;
}
