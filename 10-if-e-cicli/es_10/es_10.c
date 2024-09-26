#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tipologia[12];
    double importo, mediaBevande, mediaRistorazioni, sommaBevande = 0, sommaRistorazione = 0;
    int bevande = 0, ristorazione = 0;

    while (1)
    {
        do
        {
            printf("Inserisci la tipologia: \n");
            scanf("%s", tipologia);
        } while (strcmp("esci", tipologia) != 0 && strcmp(tipologia, "bevande") != 0 && strcmp(tipologia, "ristorazione") != 0);

        if (strcmp(tipologia, "esci") == 0)
        {
            break;
        }

        do
        {
            printf("Inserisci l' importo: \n");
            scanf("%lf", &importo);
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
    }

    if (ristorazione > bevande)
    {
        printf("Sono state vendute più ristorazioni\n");
    }
    else
    {
        printf("Sono state vendute più bevande\n");
    }

    /* prima di calcolare la media e visualizzarla,
    controllo che il numero di bevande e di ristorazioni sia maggiore di 0,
    altrimenti la divisione risulterà impossibile */
    if (bevande > 0)
    {
        mediaBevande = sommaBevande / (double)bevande;
        printf("La media delle bevande è: %f\n", mediaBevande);
    }
    else
    {
        printf("Media non disponibile. Nessuna bevanda venduta\n");
    }
    if (ristorazione > 0)
    {
        mediaRistorazioni = sommaRistorazione / (double)ristorazione;
        printf("La media delle ristorazioni è: %f\n", mediaRistorazioni);
    }
    else
    {
        printf("Media non disponibile. Nessuna ristorazione venduta\n");
    }
}