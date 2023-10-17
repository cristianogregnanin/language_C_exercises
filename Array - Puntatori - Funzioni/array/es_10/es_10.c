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

    for (i = 0; i < 2; i++)
    {
        str_giorno[k] = argv[1][i];
        k++;
    }
    giorno = atoi(str_giorno);

    if (giorno > 31 || giorno < 1)
    {
        printf("Data invalida \n");
        return -1;
    }
    k = 0;
    for (i = 2; i < 4; i++)
    {
        str_mese[k] = argv[1][i];
        k++;
    }

    mese = atoi(str_mese);
    if (mese > 12 || mese < 1)
    {
        printf("Data invalida \n");
        return -1;
    }
    k = 0;
    for (i = 4; i < 8; i++)
    {
        str_anno[k] = argv[1][i];
        k++;
    }
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
