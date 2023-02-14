#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int contMB = 0, contMR = 0, contB = 0, contR = 0;
    float sommaBevande = 0, sommaRistorazioni = 0, bevande, ristorazioni;
    float mBevande = 0, mRistorazioni = 0;
    char stringa[20];
    do
    {
        printf("Inserisci il tipo di azione che vuoi effettuare: Bevande o Ristorazioni. Scrivi esci per uscire \n");
        scanf("%s", stringa);
        if (strcmp(stringa,"ristorazioni")==0)
        {
            contR++;
            contMR++;
            printf("Inserisci l'importo della ristorazione \n");
            scanf("%f", &ristorazioni);
            sommaRistorazioni = sommaRistorazioni + ristorazioni;
        }
        if (strcmp(stringa,"bevande")==0)
        {
            contB++;
            contMB++;
            printf("Inserisci l'importo delle bevande \n");
            scanf("%f", &bevande);
            sommaBevande = sommaBevande + bevande;
        }
    } while (strcmp(stringa,"esci")!=0);
    mBevande = sommaBevande / contMB;
    mRistorazioni = sommaRistorazioni / contMR;
    printf("La media delle bevande è %1.f \n", mBevande);
    printf("La media delle ristorazioni è %1.f \n", mRistorazioni);
    printf("La somma delle ristorazioni è %1.f \n", sommaRistorazioni);
    printf("La somma delle bevande è %1.f \n", sommaBevande);
    if (contB > contR)
    {
        printf("Sono state vendute più bevande \n");
    }
    else
    {
        printf("Sono state vendute più ristorazioni \n");
    }
    return 0;
}
