#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tipologia[12];
    double importo, mediaBevande, mediaRistorazioni, sommaBevande = 0, sommaRistorazione = 0;
    int bevande = 0, ristorazione = 0;

    do
    {
        do
        {
            printf("Inserisci la tipologia: \n");
            scanf("%s", tipologia);
        } while (strcmp("esci", tipologia) != 0 && strcmp(tipologia, "bevande") != 0 && strcmp(tipologia, "ristorazione") != 0);

        do
        {
            printf("Inserisci l' importo: \n");
            scanf("%f", &importo);
        } while (importo <= 0);

        if (strcmp(tipologia, "bevande") == 0)
        {
            bevande++;
            sommaBevande = sommaBevande + importo;
        }

        if (strcmp(tipologia, "ristorazione") == 0)
        {
            ristorazione++;
            sommaRistorazione = sommaRistorazione + importo;
        }

    } while (strcmp("esci", tipologia) != 0);

    if (ristorazione > bevande)
    {
        printf("Sono state vendute più ristorazioni");
    }
    else
    {
        printf("Sono state vendute più bevande");
    }

    mediaBevande = sommaBevande / (double)bevande;
    mediaRistorazioni = sommaRistorazione / (double)ristorazione;

    printf("La media delle bevande è: %f\n", mediaBevande);
    printf("La media delle ristorazioni è: %f\n", mediaRistorazioni);
}