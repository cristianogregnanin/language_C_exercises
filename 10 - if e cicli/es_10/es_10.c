//Corsini Tommaso
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tipologia[12];
    double conto, mediaBibite, mRistoro, sBibite = 0, sRistoro = 0;
    int bibite = 0, ristoro = 0;

    do
    {
        do
        {
            printf("Inserisci la tipologia: \n");
            scanf("%s", tipologia);
        } while (strcmp("esci", tipologia) != 0 && strcmp(tipologia, "bibite") != 0 && strcmp(tipologia, "ristoro") != 0);

        do
        {
            printf("Inserisci l' importo: \n");
            scanf("%f", &conto);
        } while (conto <= 0);

        if (strcmp(tipologia, "bibite") == 0)
        {
            bibite++;
            sBibite = sBibite + conto;
        }

        if (strcmp(tipologia, "ristoro") == 0)
        {
            ristoro++;
            sRistoro = sRistoro + conto;
        }

    } while (strcmp("esci", tipologia) != 0);

    if (ristoro > bibite)
    {
        printf("Sono state vendute più ristori");
    }
    else
    {
        printf("Sono state vendute più bibite");
    }

    mBibite = sBibite / (double)bibite;
    mRistoro = sRistoro / (double)ristoro;

    printf("La media delle bibite è: %f\n", mBibite);
    printf("La media delle ristorazioni è: %f\n", mRistoro);
    return0;
}
